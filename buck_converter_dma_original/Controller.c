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
#include "Controller.h"
#include "ls_algorithm.h"
#include "transient_det.h"
//
// Main
//
float32_t kpv =0.0102;
float32_t kiv = 3.6684e-05;
float32_t kpi =0.2486;
float32_t kii = 0.0207;

// Transient detection flag 
bool transient_det_res; 
// Fault location interruptions
volatile uint16_t data_ready     = 0; 
volatile uint16_t ls_alg_trigger = 0; 

// CLA shared declarations 
float32_t R_out=0.0f; 
float32_t L_out=0.0f; 
float32_t R_err=0.0f; 
float32_t L_err=0.0f;
float32_t R_real=5.12f; 
float32_t L_real=0.0001219f;

#pragma DATA_SECTION(R_out,    "Cla1ToCpuMsgRAM");
#pragma DATA_SECTION(L_out,    "Cla1ToCpuMsgRAM");
#pragma DATA_SECTION(R_err,    "Cla1ToCpuMsgRAM");
#pragma DATA_SECTION(L_err,    "Cla1ToCpuMsgRAM");
#pragma DATA_SECTION(R_real,   "Cla1ToCpuMsgRAM");
#pragma DATA_SECTION(L_real,   "Cla1ToCpuMsgRAM");

// Sample fault location data 
uint16_t  vo_samples[BUFF_SAMPLES];
uint16_t  io_samples[BUFF_SAMPLES];
float32_t dio_samples[BUFF_SAMPLES];

#pragma DATA_SECTION(vo_samples,    "ramgs0");
#pragma DATA_SECTION(io_samples,    "ramgs0");
#pragma DATA_SECTION(dio_samples,   "ramgs0");

const void * VO_data_dest   = (const void *) vo_samples;
const void * VO_data_source = (const void *) myADC1_RESULT_BASE;
const void * IO_data_dest   = (const void *) io_samples;
const void * IO_data_source = (const void *) myADC2_RESULT_BASE;

// Test CLA 
uint16_t  vo_sample_test;
uint16_t  io_sample_test;

//#pragma DATA_SECTION(vo_sample_test,    "CpuToCla1MsgRAM");
//#pragma DATA_SECTION(io_sample_test,    "CpuToCla1MsgRAM");

void main(void)
{

    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Disable pin locks and enable internal pull-ups.
    //
    Device_initGPIO();

    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    //
    // PinMux and Peripheral Initialization
    //
    Board_init();

    //
    // C2000Ware Library initialization
    //
    C2000Ware_libraries_init();

    //
    // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
    //

    // Initialize the controllers
    init_PI(&Vo_controller,kpv,kiv);
    init_PI(&Il_controller,kpi,kii);

    // Initialize transient detection
    //init_detector(); 

    EINT;
    ERTM;
    while(1)
    {
    }
}

void INT_ControlPWM_ISR(void){
    GPIO_writePin(debug_pin,1);
    EPWM_clearEventTriggerInterruptFlag(ControlPWM_BASE);
    Interrupt_clearACKGroup(INT_ControlPWM_INTERRUPT_ACK_GROUP);
    average_samples();
    duty_cycle_calculation();
    transient_det_res = transient_detector(Vo_avg, Il_avg); 
    GPIO_writePin(transient_det_pin, transient_det_res);
    EPWM_setCounterCompareValue(ControlPWM_BASE, EPWM_COUNTER_COMPARE_A,d*PWM_TICKS_PERIOD);
    GPIO_writePin(debug_pin,0);
}

void average_samples(void){
    Iin_avg = (ADCA_results[0]*IIN_SCALE + IIN_OFST +ADCA_results[1]*IIN_SCALE + IIN_OFST);
    Io_avg = (ADCB_results[0]*IOUT_SCALE + IOUT_OFST +ADCB_results[1]*IOUT_SCALE + IOUT_OFST);
    Il_avg = (ADCC_results[4]*IL_SCALE + IL_OFST +ADCC_results[5]*IL_SCALE + IL_OFST);
    Vin_avg = (ADCC_results[2]*VIN_SCALE + VIN_OFST +ADCC_results[3]*VIN_SCALE + VIN_OFST);
    Vo_avg = (ADCC_results[0]*VOUT_SCALE + VOUT_OFST +ADCC_results[1]*VOUT_SCALE + VOUT_OFST);
    return;
}

void INT_myDMA0_ISR(void){
//    Il_measured[measure_counter_ADC0] = (ADCC_results[measure_counter_ADC0+2*num_samples]*IL_SCALE + IL_OFST);
//    Vin_measured[measure_counter_ADC0] = (ADCC_results[measure_counter_ADC0]*VIN_SCALE + VIN_OFST);
//    Vo_measured[measure_counter_ADC0] = (ADCC_results[measure_counter_ADC0+num_samples]*VOUT_SCALE + VOUT_OFST);
    Interrupt_clearACKGroup(INT_myDMA0_INTERRUPT_ACK_GROUP);
//    measure_counter_ADC0++;
}

void INT_myDMA3_ISR(void){
    DMA_disableInterrupt(myDMA3_BASE);
    DMA_stopChannel(myDMA3_BASE);
    Interrupt_clearACKGroup(INT_myDMA3_INTERRUPT_ACK_GROUP);
    data_ready+=1; 
    if (data_ready==2) {
       data_ready = 0;  
       vo_sample_test = vo_samples[2];
       io_sample_test = io_samples[2];
       GPIO_writePin(trigger_ls, 1);
    }    
}

void INT_myDMA4_ISR(void){
    DMA_disableInterrupt(myDMA4_BASE);
    DMA_stopChannel(myDMA4_BASE);
    Interrupt_clearACKGroup(INT_myDMA4_INTERRUPT_ACK_GROUP);
    data_ready+=1; 
    if (data_ready==2) {
       data_ready = 0;  
       vo_sample_test = vo_samples[2];
       io_sample_test = io_samples[2];
       GPIO_writePin(trigger_ls, 1);
    }    
}

void INT_transient_det_pin_XINT_ISR(void){
    DMA_enableInterrupt(myDMA3_BASE);
    DMA_startChannel(myDMA3_BASE);
    DMA_enableInterrupt(myDMA4_BASE);
    DMA_startChannel(myDMA4_BASE);
    Interrupt_clearACKGroup(INT_transient_det_pin_XINT_INTERRUPT_ACK_GROUP);   
}

void INT_trigger_ls_XINT_ISR(void){
    ESTOP0; 
    GPIO_writePin(trigger_ls, 0);
    Interrupt_clearACKGroup(INT_trigger_ls_XINT_INTERRUPT_ACK_GROUP);   
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


__interrupt void cla1Isr1(void)
{
    ESTOP0; 
    //GPIO_togglePin(trigger_ls);
    Interrupt_clearACKGroup(INT_myCLA01_INTERRUPT_ACK_GROUP);
    //Interrupt_clearACKGroup(INT_trigger_ls_XINT_INTERRUPT_ACK_GROUP);
}


