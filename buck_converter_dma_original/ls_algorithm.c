#include "ls_algorithm.h"


// LS algorithm with QR decomposition
void ls_alg(void){ 

    // Local variables declaration
    int16_t   N_samples  = (BUFF_SAMPLES + 1);
    float32_t n1_partial = 0.0;
    float32_t n2_partial = 0.0;
    int16_t   piv0 = 0;
    int16_t   piv1 = 1;
    int16_t   i    = 0;

    // Derivatives
    for(i=0; i<N_samples; i++){
        if(i == 0)
            dio_samples[i] = (io_samples[1] - io_samples[0]) / TSMPL;
        else if(i == N_samples-1)
            dio_samples[i] = (io_samples[i] - io_samples[i-1]) / TSMPL;
        else
            dio_samples[i] = (io_samples[i+1] - io_samples[i-1]) / (2.0f*TSMPL);

        n1_partial += io_samples[i]*io_samples[i];
        n2_partial += dio_samples[i]*dio_samples[i];
    }

    // Pivoting
    if(n2_partial > n1_partial){
        piv0 = 1;
        piv1 = 0;
    }

    float32_t *col0 = (piv0==0) ? (float32_t*)io_samples : dio_samples;
    float32_t *col1 = (piv1==0) ? (float32_t*)io_samples : dio_samples;

    // Householder 1 

    float32_t alpha = 0.0f;
    float32_t v_h[N_samples];
    float32_t vv=0.0f;
    float32_t dot=0.0f;
    float32_t dot1=0.0f;

    for(i=0;i<N_samples;i++) {

        alpha += col0[i]*col0[i];
        v_h[i] = col0[i];

        if(i>0){
            vv   += v_h[i]*v_h[i];
            dot  += v_h[i]*col1[i];
            dot1 += v_h[i]*vo_samples[i];
        }
    }

    alpha = sqrtf(alpha);

    if(col0[0] > 0)
        alpha = -alpha;

    v_h[0] -= alpha;

    vv   += v_h[0]*v_h[0];
    dot  += v_h[0]*col1[0];
    dot1 += v_h[0]*vo_samples[0];

    float32_t beta = 2.0f / vv;

    for(i=0;i<N_samples;i++) {
        col1[i] -= beta * v_h[i] * dot;
        vo_samples[i] -= beta * v_h[i] * dot1;
    }

    /* Householder 2 */

    float32_t alpha2=0.0f;
    float32_t v2[N_samples];
    float32_t v2v2=0.0f;
    float32_t dot2=0.0f;

    for(i=0;i<N_samples;i++) {

        if(i>0)
            alpha2 += col1[i]*col1[i];

        if(i < N_samples-1){
            v2[i] = col1[i+1];
            v2v2 += v2[i]*v2[i];
            dot2 += v2[i]*vo_samples[i+1];
        }
    }

    alpha2 = sqrtf(alpha2);

    if(col1[1] > 0)
        alpha2 = -alpha2;

    v2[0] -= alpha2;

    v2v2 += v2[0]*v2[0];
    dot2 += v2[0]*vo_samples[1];

    float32_t beta2 = 2.0f / v2v2;

    for(i=0;i<N_samples-1;i++)
        vo_samples[i+1] -= beta2*v2[i]*dot2;

    // Back-substitution

    float32_t R11 = alpha;
    float32_t R12 = col1[0];
    float32_t R22 = alpha2;

    float32_t x2 = vo_samples[1] / R22;
    float32_t x1 = (vo_samples[0] - R12*x2) / R11;

    float32_t sol[2]={0};

    sol[piv0] = x1;
    sol[piv1] = x2;

    R_out = sol[0];
    L_out = sol[1];

    return;
}

// Calculate accuracy of the estimation 
void accuracy(void){
    
    R_err = fabsf((R_out-R_real)/R_real)*100.0f;
    L_err = fabsf((L_out-L_real)/L_real)*100.0f;      

    return;       
}

