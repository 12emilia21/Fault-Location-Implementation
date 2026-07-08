#include "moving_avg.h"

#define AVG_SAMPLES 100

// Variable declaration
uint16_t io_filter_buff[AVG_SAMPLES];

int16_t head_filter;
float32_t io_filter_sum;

void init_filter(void) 
{
    int16_t i;

    for(i=0;i<AVG_SAMPLES;i++)
    {
        io_filter_buff[i]=0;
    }
    
    head_filter    = 0;
    io_filter_sum  = 0;

    return;
}

float32_t filter(uint16_t io_sim)
{
    float32_t io_avg;

    // Remove old sample
    float32_t old_io_filter = io_filter_buff[head_filter];

    io_filter_sum -= old_io_filter;

    // Store new sample 
    io_filter_buff[head_filter] = io_sim;
    io_filter_sum += io_sim;

    // Update avg values
    io_avg = io_filter_sum / AVG_SAMPLES;

    // Step circular buffer
    head_filter++;
    if(head_filter>=AVG_SAMPLES)
        head_filter=0;
	 
	return io_avg; 
}
