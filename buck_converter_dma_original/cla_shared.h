#ifndef CLA_SHARED_H
#define CLA_SHARED_H

#define BUFF_SAMPLES    ((uint16_t)36)   
#define TSMPL           ((float32_t)50e-6)         //fsw = 10e3, oversample = 2
#define N_SAMPLES       ((uint16_t)2)   
#define N_COMPUTE       ((uint16_t)(BUFF_SAMPLES/N_SAMPLES))
#define REAL_R_FAULT    ((float32_t)5.8667)
#define REAL_L_FAULT    ((float32_t)0.00012698) 

extern volatile float32_t R_out;
extern volatile float32_t L_out;
extern volatile float32_t R_err;
extern volatile float32_t L_err;
extern volatile float32_t R_real;
extern volatile float32_t L_real;

extern float32_t vo_sample_test[N_SAMPLES];
extern float32_t io_sample_test[N_SAMPLES];

extern uint16_t s_count; 
extern bool     less_smpls;

__attribute__((interrupt)) void Cla1Task1(void);
__attribute__((interrupt)) void Cla1Task2(void);

#endif /* CLA_SHARED_H */
