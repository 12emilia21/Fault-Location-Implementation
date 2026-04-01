#ifndef TRANSIENT_DET_H
#define TRANSIENT_DET_H

// Includes
#include <math.h>
#include "defines.h"

// Variable declaration
float32_t vo_buff[N_AVG];
float32_t io_buff[N_AVG];
float32_t tr_buff[N_AVG];

int16_t head;

float32_t vo_sum;
float32_t io_sum;
float32_t tr_sum;

bool transient_det_res; 

#endif 

// Function prototypes
void init_detector(void); 
bool transient_detector(float32_t vo_sim,float32_t io_sim); 



