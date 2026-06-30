#ifndef TRANSIENT_DET_H
#define TRANSIENT_DET_H

// Includes
#include <math.h>
#include "c2000ware_libraries.h"

// Defines
#define N_AVG        ((uint16_t)8)      //16)              
#define RATED_VO     ((float32_t)12)    //48)
#define RATED_IO     ((float32_t)2.25)  //9)
#define VO_VAR_VAL   ((float32_t)(0.05*RATED_VO))
#define IO_VAR_VAL   ((float32_t)(0.05*RATED_IO))

#endif 

// Function prototypes
void init_detector(void); 
bool transient_detector(float32_t vo_sim,float32_t io_sim); 



