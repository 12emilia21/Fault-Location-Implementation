/*
    File: defines.h 

    File with definitions needed throughout the implementation.
    General Inlcudes, used by many .c files.  
*/

// Includes
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"
#include "control_functions.h"

// Circuit characteristics 
#define RATED_VO        ((float32_t)48)
#define RATED_IO        ((float32_t)20.83)
#define R_FAULT         ((float32_t)0.01)
#define L_LINE          ((float32_t)5.4857e-5f)
#define R_LINE          ((float32_t)0.2304)
#define FAULT_LOC       ((float32_t)1)            //Value between 0 and 1
#define REAL_L_FAULT    ((float32_t)(FAULT_LOC*L_LINE))
#define REAL_R_FAULT    ((float32_t)((FAULT_LOC*R_LINE)+R_FAULT)) 
#define TSMPL           ((float32_t)5e-6)         //fsw = 50e3, oversample = 4

// Transient detection  
#define N_AVG        ((uint16_t)16)                //(BUFF_SAMPLES/16) sampling at 100kHz.  Orig: (BUFF_SAMPLES/8) Samples required: half resonance period of the tank (sampling at 200kHz)
#define VO_VAR_VAL   ((float32_t)(0.02*RATED_VO))
#define IO_VAR_VAL   ((float32_t)(0.025*RATED_IO))

// LS algorithm implementation 
#define BUFF_SAMPLES     ((uint16_t)128)    // (original 258 pero para que sea efectiva la implementacion) Samples required: 4 resonance periods of the tank (sampling at 200kHz)







