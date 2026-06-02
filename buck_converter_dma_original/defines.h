/*
    File: defines.h 

    Defines used in CPU and CLA
*/

// Circuit characteristics 

#define R_FAULT         ((float32_t)0.01)
#define L_LINE          ((float32_t)5.4857e-5f)
#define R_LINE          ((float32_t)0.2304)
#define FAULT_LOC       ((float32_t)1)                  // Value between 0 and 1
#define REAL_R_LOAD     ((float32_t)5.8667)             // No fault 
#define REAL_R_FAULT    ((float32_t)0.5433)             // Fault 
#define REAL_L_FAULT    ((float32_t)0.00012698) 

// LS algorithm 
#define SW_PERIOD       ((float32_t)100e-6)             // RTbox implementation 10kHz
#define TWO_RES         ((uint16_t)20)                  // PWM pulses required to cover 2 converter resonance cycles
#define N_SAMPLES       ((uint16_t)4)  
#define BUFF_SAMPLES    ((uint16_t)TWO_RES*N_SAMPLES)
#define TSMPL           ((float32_t)SW_PERIOD/N_SAMPLES)//25e-6)         //fsw = 10e3, oversample = 4  
#define N_COMPUTE       ((uint16_t)(BUFF_SAMPLES/N_SAMPLES))
//#define TSMPL           ((float32_t)50e-6)         //fsw = 10e3, oversample = 2

// Algorithm timer 
#define TIMER_PRESCALER 100
#define TIMER_PERIOD    10e-3
#define SYSCLK          100e6

// Saturation of sensors
#define V_SAT_H           ((float32_t)49)//49.27)
#define V_SAT_L           ((float32_t)0.0)
#define I_SAT_H           ((float32_t)20.5)//20.625)
#define I_SAT_L           ((float32_t)0.0)

