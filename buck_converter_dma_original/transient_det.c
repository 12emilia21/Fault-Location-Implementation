#include "transient_det.h"

// Variable declaration
float32_t vo_buff[N_AVG];
float32_t io_buff[N_AVG];
float32_t tr_buff[N_AVG];

int16_t head;

float32_t vo_sum;
float32_t io_sum;
float32_t tr_sum;

void init_detector(void) 
{
    int16_t i;

    for(i=0;i<N_AVG;i++)
    {
        vo_buff[i]=0;
        io_buff[i]=0;
        tr_buff[i]=0;
    }
    
    head    = 0;
    vo_sum  = 0;
    io_sum  = 0;
    tr_sum  = 0;

    return;
}

bool transient_detector(float32_t vo_sim,float32_t io_sim)
{
    bool      tr_det_2; 
    float32_t c_est; 
    float32_t tr_det_est; 
    float32_t tr_avg; 
    float32_t vo_avg;
    float32_t io_avg;

    // Remove old sample
    float32_t old_vo = vo_buff[head];
    float32_t old_io = io_buff[head];
    float32_t old_tr = tr_buff[head];

    vo_sum -= old_vo;
    io_sum -= old_io;
    tr_sum -= old_tr;

    // Store new sample 
    vo_buff[head] = vo_sim;
    io_buff[head] = io_sim;

    vo_sum += vo_sim;
    io_sum += io_sim;

    // Update avg values
    vo_avg = vo_sum / N_AVG;
    io_avg = io_sum / N_AVG;

    // In or out of area
    c_est = ((vo_sim - vo_avg)*(vo_sim - vo_avg))/(VO_VAR_VAL*VO_VAR_VAL) +
            ((io_sim - io_avg)*(io_sim - io_avg))/(IO_VAR_VAL*IO_VAR_VAL);

    tr_det_est = (c_est > 1.0) ? 1.0 : 0.0;

    // Update transient buffer
    tr_buff[head] = tr_det_est;
    tr_sum += tr_det_est;

    // Define transient trigger
    tr_avg = tr_sum / N_AVG;

    if(tr_avg > 0.0)
        tr_det_2 = 1.0;
    else
        tr_det_2 = 0.0;

    // Step circular buffer
    head++;
    if(head>=N_AVG)
        head=0;
	 
	return tr_det_2; 
}
