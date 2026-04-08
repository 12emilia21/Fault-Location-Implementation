#ifndef CLA_SHARED_H
#define CLA_SHARED_H

#define BUFF_SAMPLES     ((int)128)   
#define TSMPL           ((float32_t)50e-6)         //fsw = 10e3, oversample = 2

extern float32_t R_out;
extern float32_t L_out;
extern float32_t R_err;
extern float32_t L_err;
extern float32_t R_real;
extern float32_t L_real;

extern int   vo_samples[BUFF_SAMPLES];
extern int   io_samples[BUFF_SAMPLES];
extern float dio_samples[BUFF_SAMPLES];

extern uint16_t  vo_sample_test;
extern uint16_t  io_sample_test;

__attribute__((interrupt)) void Cla1Task1(void);
__attribute__((interrupt)) void Cla1Task2(void);

#endif /* CLA_SHARED_H */
