#ifndef TRANSIENT_DET_H
#define TRANSIENT_DET_H

// Includes
#include <math.h>
#include "c2000ware_libraries.h"

// Defines
#define N_AVG        ((uint16_t)16)              
#define RATED_VO     ((float32_t)12)//48)
#define RATED_IO     ((float32_t)2.25)//20.83)  
#define VO_VAR_VAL   ((float32_t)(0.05*RATED_VO)) //240mV
#define IO_VAR_VAL   ((float32_t)(0.05*RATED_IO)) //56mA
//#define VO_VAR_VAL   ((float32_t)(0.02*RATED_VO)) //240mV
//#define IO_VAR_VAL   ((float32_t)(0.025*RATED_IO)) //56mA

#endif 

// Function prototypes
void init_detector(void); 
bool transient_detector(float32_t vo_sim,float32_t io_sim); 



