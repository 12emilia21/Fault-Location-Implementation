/*
    File: defines.h 

    Defines used in CPU and CLA
*/

// Circuit characteristics 

#define R_FAULT             ((float32_t)0.01)
#define L_LINE              ((float32_t)5.4857e-5f)
#define R_LINE              ((float32_t)0.2304)
#define FAULT_LOC           ((float32_t)50)                // Value between 0 and 100

// Simulation 

// -- No fault values --
#define REAL_R_LOAD         ((float32_t)5.8667)             // No fault 
#define REAL_L_LOAD         ((float32_t)6.3492e-04)         // No fault 

// -- Fault values at 100% length --
#define REAL_R_FAULT_100    ((float32_t)0.5433)             
#define REAL_L_FAULT_100    ((float32_t)6.3492e-4) 
// -- Fault values at 75% length --
#define REAL_R_FAULT_75     ((float32_t)0.41)            
#define REAL_L_FAULT_75     ((float32_t)4.7619e-4) 
// -- Fault values at 50% length --
#define REAL_R_FAULT_50     ((float32_t)0.2766)        
#define REAL_L_FAULT_50     ((float32_t)3.1746e-4) 
// -- Fault values at 25% length --
#define REAL_R_FAULT_25     ((float32_t)0.1433)
#define REAL_L_FAULT_25     ((float32_t)1.5873e-4)
// -- Fault values at 10% length --
#define REAL_R_FAULT_10     ((float32_t)0.0633)
#define REAL_L_FAULT_10     ((float32_t)6.3492e-5)

// LS algorithm 
#define SW_PERIOD       ((float32_t)100e-6)             // RTbox implementation 10kHz
#define TWO_RES         ((uint16_t)18)                  // PWM pulses required to cover 2 converter resonance cycles
#define N_SAMPLES       ((uint16_t)4)  
#define BUFF_SAMPLES    ((uint16_t)TWO_RES*N_SAMPLES)
#define TSMPL           ((float32_t)SW_PERIOD/N_SAMPLES)  //fsw = 10e3, oversample = 4  
#define N_COMPUTE       ((uint16_t)(TWO_RES))
#define BLOCKS          ((uint16_t)10)
#define SEL_BLK         ((uint16_t)1)
#define OFFSET_PWM      ((uint16_t)(SEL_BLK-1)*(TWO_RES/BLOCKS))
#define OFFSET          ((uint16_t)OFFSET_PWM*N_SAMPLES)
#define BLOCK_END       ((uint16_t)OFFSET_PWM+TWO_RES/BLOCKS)

// Algorithm timer 
#define TIMER_PRESCALER 100
#define TIMER_PERIOD    10e-3
#define SYSCLK          100e6

// ADC definitions
#define ADC_CODES           ((uint16_t)(4096))
#define I_SCALE             70//10//21
#define V_SCALE             85//20//62

#define IIN_MAX ((float32_t)I_SCALE)
#define IIN_SCALE IIN_MAX/ADC_CODES
#define IIN_OFST 25

#define IOUT_MAX ((float32_t)I_SCALE)
#define IOUT_SCALE IOUT_MAX/ADC_CODES
#define IOUT_OFST 25

#define IL_MAX ((float32_t)I_SCALE)
#define IL_SCALE IL_MAX/ADC_CODES
#define IL_OFST 25

#define VIN_MAX ((float32_t)V_SCALE)
#define VIN_SCALE VIN_MAX/ADC_CODES
#define VIN_OFST 0

#define VOUT_MAX ((float32_t)V_SCALE)
#define VOUT_SCALE VOUT_MAX/ADC_CODES
#define VOUT_OFST 30

// Saturation of sensors
// -0.1 to account for discrepancies in the measurements
#define V_SAT_H           ((float32_t)V_SCALE-0.1)//20)//49.27)
#define V_SAT_L           ((float32_t)-V_SCALE)
#define I_SAT_H           ((float32_t)I_SCALE-0.1)//10)//20.5)//20.625)
#define I_SAT_L           ((float32_t)-I_SCALE)
