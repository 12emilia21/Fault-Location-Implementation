#ifndef MOVING_AVG_H
#define MOVING_AVG_H

// Includes
#include <math.h>
#include "c2000ware_libraries.h"

#endif 

// Samples to average
#define AVG_SAMPLES 4

typedef struct {
    float32_t samples[AVG_SAMPLES];
    float32_t hist_smpl[AVG_SAMPLES]; 
} filt_data;

// Function prototypes
void init_filter(filt_data* data, float32_t* cla_array); 
void filter(filt_data* data, float32_t* cla_array); 
