#ifndef LS_ALGORITHM_H
#define LS_ALGORITHM_H

// Includes
#include <math.h>
#include "defines.h"

// Variable declaration
float32_t R_out=0.0f; 
float32_t L_out=0.0f; 
float32_t R_err=0.0f; 
float32_t L_err=0.0f;
float32_t R_real=0.0f; 
float32_t L_real=0.0f;

// Sample fault location data 
uint16_t vo_samples[BUFF_SAMPLES];
uint16_t io_samples[BUFF_SAMPLES];
uint16_t dio_samples[BUFF_SAMPLES];
#pragma DATA_SECTION(vo_samples,    "ramgs0");
#pragma DATA_SECTION(io_samples,    "ramgs0");

const void * VO_data_dest   = (const void *) vo_samples;
const void * VO_data_source = (const void *) myADC1_RESULT_BASE;
const void * IO_data_dest   = (const void *) io_samples;
const void * IO_data_source = (const void *) myADC2_RESULT_BASE;

// Fault location interruptions
uint16_t data_ready = 0; 

#endif 

// Function prototypes
void ls_alg(void); 
void accuracy(void); 
