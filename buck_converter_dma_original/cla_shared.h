#ifndef CLA_SHARED_H
#define CLA_SHARED_H

#include "defines.h"

extern volatile float32_t R_out;
extern volatile float32_t L_out;

extern float32_t vo_sample_test[N_SAMPLES];
extern float32_t io_sample_test[N_SAMPLES];

extern uint16_t s_count; 
extern bool     less_smpls;

__attribute__((interrupt)) void Cla1Task1(void);

#endif /* CLA_SHARED_H */
