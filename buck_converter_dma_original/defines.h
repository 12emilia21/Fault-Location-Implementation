/*
    File: defines.h 

    Defines used in CPU and CLA
*/

// Circuit characteristics 

#define R_FAULT             ((float32_t)0.01)
#define L_LINE              ((float32_t)5.4857e-5f)
#define R_LINE              ((float32_t)0.2304)
#define FAULT_LOC           ((float32_t)25)                // Value between 0 and 100

// -- No fault values --
#define REAL_R_LOAD         ((float32_t)6.56)//Simulation: 5.8667)             // No fault 
#define REAL_L_LOAD         ((float32_t)115.8e-6)//Simulation: 0.00012698)         // No fault 

// -- Fault values at 100% length --
#define REAL_R_FAULT_100    ((float32_t)0.499)//Simulation: 0.5433)             
#define REAL_L_FAULT_100    ((float32_t)90.88e-6)//Simulation: 0.00012698) 
// -- Fault values at 75% length --
#define REAL_R_FAULT_75     ((float32_t)0.367)            
#define REAL_L_FAULT_75     ((float32_t)68.6e-6) 
// -- Fault values at 50% length --
#define REAL_R_FAULT_50     ((float32_t)0.263)        
#define REAL_L_FAULT_50     ((float32_t)46.2e-6) 
// -- Fault values at 25% length --
#define REAL_R_FAULT_25     ((float32_t)0.159)
#define REAL_L_FAULT_25     ((float32_t)24.2e-6)

// LS algorithm 
#define SW_PERIOD       ((float32_t)20e-6)                // Real platform 50khz
#define TWO_RES         ((uint16_t)18)                    // PWM pulses required to cover 2 converter resonance cycles
#define N_SAMPLES       ((uint16_t)4)  
#define BUFF_SAMPLES    ((uint16_t)TWO_RES*N_SAMPLES)
#define TSMPL           ((float32_t)SW_PERIOD/N_SAMPLES)  //fsw = 50e3, oversample = 4  
#define N_COMPUTE       ((uint16_t)(BUFF_SAMPLES/N_SAMPLES))

// Algorithm timer 
#define TIMER_PRESCALER 100
#define TIMER_PERIOD    10e-3
#define SYSCLK          100e6

// ADC definitions
#define ADC_CODES           ((uint16_t)(4096))
#define I_SCALE             17//20.625
#define V_SCALE             49.27//62

#define IIN_MAX ((float32_t)I_SCALE)
#define IIN_SCALE IIN_MAX/ADC_CODES
#define IIN_OFST 0

#define IOUT_MAX ((float32_t)22.289)
#define IOUT_SCALE IOUT_MAX/ADC_CODES
#define IOUT_OFST 11.14

#define IL_MAX ((float32_t)I_SCALE)
#define IL_SCALE IL_MAX/ADC_CODES
#define IL_OFST 0

#define VIN_MAX ((float32_t)V_SCALE)
#define VIN_SCALE VIN_MAX/ADC_CODES
#define VIN_OFST 0

#define VOUT_MAX ((float32_t)57.798)
#define VOUT_SCALE VOUT_MAX/ADC_CODES
#define VOUT_OFST 14.47

// DAC definitions
#define DAC_CODES           ((uint16_t)(4096))
#define L_MAX_VALUE         ((float32_t)130e-6)

// Saturation of sensors
// -0.1 to account for discrepancies in the measurements
#define V_SAT_H           ((float32_t)57.6)//20)//49.27)
#define V_SAT_L           ((float32_t)-14)
#define I_SAT_H           ((float32_t)11)//10)//20.5)//20.625)
#define I_SAT_L           ((float32_t)-11)

