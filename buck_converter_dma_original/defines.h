/*
    File: defines.h 

    Defines used in CPU and CLA
*/

// Circuit characteristics 

#define R_FAULT         ((float32_t)0.01)
#define L_LINE          ((float32_t)5.4857e-5f)
#define R_LINE          ((float32_t)0.2304)
#define FAULT_LOC       ((float32_t)1)                  // Value between 0 and 1
#define REAL_R_FAULT    ((float32_t)5.8667)             // No fault 
#define REAL_L_FAULT    ((float32_t)0.00012698) 

// LS algorithm 

#define BUFF_SAMPLES    ((uint16_t)36*2)   
#define TSMPL           ((float32_t)50e-6)         //fsw = 10e3, oversample = 2
#define N_SAMPLES       ((uint16_t)4)   
#define N_COMPUTE       ((uint16_t)(BUFF_SAMPLES/N_SAMPLES))







