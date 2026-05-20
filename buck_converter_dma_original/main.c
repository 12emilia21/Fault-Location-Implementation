//#############################################################################
//
// FILE:   empty_driverlib_main.c
//
//! \addtogroup driver_example_list
//! <h1>Empty Project Example</h1> 
//!
//! This example is an empty project setup for Driverlib development.
//!
//
//#############################################################################
//
//
// $Copyright:
// Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

//
// Included Files
//
#include "main.h"

// Controller
float32_t kpv =0.0102;
float32_t kiv = 3.6684e-05;
float32_t kpi =0.2486;
float32_t kii = 0.0207;

// Transient detection result
bool     transient_det_res; 
uint16_t k;

// CLA to CPU
volatile float32_t R_out=0.0f; 
volatile float32_t L_out=0.0f; 

#pragma DATA_SECTION(R_out,    "Cla1ToCpuMsgRAM");
#pragma DATA_SECTION(L_out,    "Cla1ToCpuMsgRAM");

// CPU to CLA
float32_t  vo_sample_test[num_samples];
float32_t  io_sample_test[num_samples];
uint16_t   s_count     = 0; 

#pragma DATA_SECTION(vo_sample_test,    "CpuToCla1MsgRAM");
#pragma DATA_SECTION(io_sample_test,    "CpuToCla1MsgRAM");
#pragma DATA_SECTION(s_count,           "CpuToCla1MsgRAM");

// Error calculation
volatile float32_t R_err  = 0.0f; 
volatile float32_t L_err  = 0.0f;

#pragma DATA_SECTION(R_err,    "ramgs0");
#pragma DATA_SECTION(L_err,    "ramgs0");

// Aux
uint32_t  get_clk     = 0; 
uint32_t  get_ls_clk  = 0; 
uint32_t  timer_count = 0; 
float32_t alg_time    = 0.0;

void main(void)
{
    // Initialize device clock and peripherals
    Device_init();

    // Disable pin locks and enable internal pull-ups.
    Device_initGPIO();

    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    Interrupt_initModule();

    // Initialize the PIE vector table with pointers to the shell Interrupt Service Routines (ISR).
    Interrupt_initVectorTable();

     // Disable sync(Freeze clock to PWM as well)
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    // PinMux and Peripheral Initialization
    Board_init();

    // Enable sync and clock to PWM
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    // C2000Ware Library initialization
    C2000Ware_libraries_init();

    // Initialize the controllers
    init_PI(&Vo_controller,kpv,kiv);
    init_PI(&Il_controller,kpi,kii);

    // Initialize transient detector 
    init_detector();

    // Check clocks 
    get_clk    = SysCtl_getClock(DEVICE_OSCSRC_FREQ);

    EINT;
    ERTM;
    while(1)
    {
    }
}

void average_samples(void){
    Iin_avg = 0.5f *((ADCC_results[0]*IIN_SCALE  - IIN_OFST ) + (ADCC_results[4]*IIN_SCALE   - IIN_OFST ));
    Il_avg  = 0.5f *((ADCC_results[1]*IL_SCALE   - IL_OFST  ) + (ADCC_results[5]*IL_SCALE    - IL_OFST  ));
    Vo_avg  = 0.5f *((ADCC_results[2]*VOUT_SCALE - VOUT_OFST) + (ADCC_results[6]*VOUT_SCALE  - VOUT_OFST));
    Io_avg  = 0.5f *((ADCB_results[0]*IOUT_SCALE - IOUT_OFST) + (ADCB_results[2]*IOUT_SCALE  - IOUT_OFST));
    Vin_avg = 0.5f *((ADCA_results[0]*VIN_SCALE  - VIN_OFST ) + (ADCA_results[1]*VIN_SCALE   - VIN_OFST ));
   
    return;
}

void samples_to_cla(void){
    vo_sample_test[0] = ADCC_results[2]*VOUT_SCALE - VOUT_OFST;
    vo_sample_test[1] = ADCC_results[3]*VOUT_SCALE - VOUT_OFST;
    vo_sample_test[2] = ADCC_results[6]*VOUT_SCALE - VOUT_OFST;
    vo_sample_test[3] = ADCC_results[7]*VOUT_SCALE - VOUT_OFST;
    io_sample_test[0] = ADCB_results[0]*IOUT_SCALE - IOUT_OFST;
    io_sample_test[1] = ADCB_results[1]*IOUT_SCALE - IOUT_OFST;
    io_sample_test[2] = ADCB_results[2]*IOUT_SCALE - IOUT_OFST;
    io_sample_test[3] = ADCB_results[3]*IOUT_SCALE - IOUT_OFST;
    return;
}

void duty_cycle_calculation(void){
    if(fixed_duty_cycle){
        d = fixed_d;
        reset_PI(&Vo_controller);
        reset_PI(&Il_controller);
    }
    else{
        Vo_error = Vo_ref - Vo_avg;
        update_PI(Vo_error,&Vo_controller);
        Il_error = Vo_controller.output - Il_avg;
        update_PI(Il_error,&Il_controller);
        d = duty_cycle_saturation(Il_controller.output);
    }
    return;
}

void err_calc(void){
    if (Io_avg > 1)
        R_err = fabsf((R_out-REAL_R_LOAD)/REAL_R_LOAD)*100.0f;
    else 
        R_err = fabsf((R_out-REAL_R_FAULT)/REAL_R_FAULT)*100.0f;
    L_err = fabsf((L_out-REAL_L_FAULT)/REAL_L_FAULT)*100.0f;

    return;
}

// ----------------- ISRs -----------------

// --- ISR for controller + estimation ---
// Obtain avg measurements and calculate duty cycle. 
// Assign samples to CLA arrays. 
// Calculate duty cycle (if fixed, maintains the same value).
// Detects transient and calculates error if the estimation is over. 

void INT_ControlPWM_ISR(void){
    EPWM_clearEventTriggerInterruptFlag(ControlPWM_BASE);
    Interrupt_clearACKGroup(INT_ControlPWM_INTERRUPT_ACK_GROUP);
    average_samples();
    samples_to_cla();
    duty_cycle_calculation();
    transient_det_res = transient_detector(Vo_avg, Il_avg);
    if (transient_det_res == 0) {
        s_count=0;
        err_calc();
    }
    GPIO_writePin(transient_det_pin, transient_det_res);
    set_duty_cycle(d);
}

// --- ISR for CLA operation ---
// Stop counter and compute the execution time. 
// (from the detection of the fault until the obtentions of the estimated parameters)

__interrupt void cla1Isr1(void)
{
    s_count+=1;
    if (s_count == BUFF_SAMPLES/N_SAMPLES) {
        CPUTimer_stopTimer(myCPUTIMER0_BASE);
        timer_count = CPUTimer_getTimerCount(myCPUTIMER0_BASE);
        alg_time = TIMER_PERIOD - timer_count*TIMER_PRESCALER/SYSCLK;
        GPIO_writePin(debug_pin,0);
    }
    
    Interrupt_clearACKGroup(INT_myCLA01_INTERRUPT_ACK_GROUP);
}

// --- ISR for transient detection/sample collection ---
// Clear GPIO to continue sending data to the CLA on every rising edge. 
// Once the amount of samples required is reached, the pin remains in 1 until "naturally cleared" (by detection algorithm).  

void INT_transient_det_pin_XINT_ISR(void){
    if (s_count == 0) {
        CPUTimer_startTimer(myCPUTIMER0_BASE);
        GPIO_writePin(debug_pin,1);
    }
    if((transient_det_res==1) && (s_count<(BUFF_SAMPLES/N_SAMPLES-1))){
        GPIO_writePin(transient_det_pin, 0);
    } 
    Interrupt_clearACKGroup(INT_transient_det_pin_XINT_INTERRUPT_ACK_GROUP);   
}

// --- ISR for the trip-zone interrupt ---
// The flags are not cleared yet since the trip condition persists (GPIO in low state). 
// The interruption is only acknowledged. 

void INT_ControlPWM_TZ_ISR(void){
    Interrupt_clearACKGroup(INT_ControlPWM_TZ_INTERRUPT_ACK_GROUP);
}

// --- ISR for the trip-zone GPIO ---
// The flags are cleared after the trip condition is cleared (GPIO rising edge). 

void INT_tz_pin_XINT_ISR(void){
    EPWM_clearTripZoneFlag(ControlPWM_BASE, (EPWM_TZ_INTERRUPT | EPWM_TZ_FLAG_OST));
    Interrupt_clearACKGroup(INT_tz_pin_XINT_INTERRUPT_ACK_GROUP);
}


