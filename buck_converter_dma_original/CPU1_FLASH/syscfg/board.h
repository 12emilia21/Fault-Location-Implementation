/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************

//
// EPWM1 -> ControlPWM Pinmux
//
//
// EPWM1_A - GPIO Settings
//
#define GPIO_PIN_EPWM1_A 0
#define ControlPWM_EPWMA_GPIO 0
#define ControlPWM_EPWMA_PIN_CONFIG GPIO_0_EPWM1_A
//
// EPWM1_B - GPIO Settings
//
#define GPIO_PIN_EPWM1_B 1
#define ControlPWM_EPWMB_GPIO 1
#define ControlPWM_EPWMB_PIN_CONFIG GPIO_1_EPWM1_B

//
// EPWM2 -> ControlPWM_fixed_fsw Pinmux
//
//
// EPWM2_A - GPIO Settings
//
#define GPIO_PIN_EPWM2_A 2
#define ControlPWM_fixed_fsw_EPWMA_GPIO 2
#define ControlPWM_fixed_fsw_EPWMA_PIN_CONFIG GPIO_2_EPWM2_A
//
// EPWM2_B - GPIO Settings
//
#define GPIO_PIN_EPWM2_B 3
#define ControlPWM_fixed_fsw_EPWMB_GPIO 3
#define ControlPWM_fixed_fsw_EPWMB_PIN_CONFIG GPIO_3_EPWM2_B

//
// EPWM3 -> ControlPWM_2fsw Pinmux
//
//
// EPWM3_A - GPIO Settings
//
#define GPIO_PIN_EPWM3_A 4
#define ControlPWM_2fsw_EPWMA_GPIO 4
#define ControlPWM_2fsw_EPWMA_PIN_CONFIG GPIO_4_EPWM3_A
//
// EPWM3_B - GPIO Settings
//
#define GPIO_PIN_EPWM3_B 5
#define ControlPWM_2fsw_EPWMB_GPIO 5
#define ControlPWM_2fsw_EPWMB_PIN_CONFIG GPIO_5_EPWM3_B
//
// GPIO33 - GPIO Settings
//
#define debug_pin_GPIO_PIN_CONFIG GPIO_33_GPIO33
//
// GPIO12 - GPIO Settings
//
#define transient_det_pin_GPIO_PIN_CONFIG GPIO_12_GPIO12
//
// GPIO16 - GPIO Settings
//
#define tz_pin_GPIO_PIN_CONFIG GPIO_16_GPIO16
//
// GPIO11 - GPIO Settings
//
#define tz_clear_pin_GPIO_PIN_CONFIG GPIO_11_GPIO11

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
#define myADC0_BASE ADCA_BASE
#define myADC0_RESULT_BASE ADCARESULT_BASE
#define myADC0_Vin ADC_SOC_NUMBER0
#define myADC0_FORCE_Vin ADC_FORCE_SOC0
#define myADC0_SAMPLE_WINDOW_Vin 55.1
#define myADC0_TRIGGER_SOURCE_Vin ADC_TRIGGER_EPWM3_SOCA
#define myADC0_CHANNEL_Vin ADC_CH_ADCIN0
#define myADC0_Iin ADC_SOC_NUMBER1
#define myADC0_FORCE_Iin ADC_FORCE_SOC1
#define myADC0_SAMPLE_WINDOW_Iin 58.1
#define myADC0_TRIGGER_SOURCE_Iin ADC_TRIGGER_EPWM3_SOCA
#define myADC0_CHANNEL_Iin ADC_CH_ADCIN3
#define myADC0_Iout1 ADC_SOC_NUMBER2
#define myADC0_FORCE_Iout1 ADC_FORCE_SOC2
#define myADC0_SAMPLE_WINDOW_Iout1 57.41
#define myADC0_TRIGGER_SOURCE_Iout1 ADC_TRIGGER_EPWM3_SOCA
#define myADC0_CHANNEL_Iout1 ADC_CH_ADCIN6
#define myADC0_Iout2 ADC_SOC_NUMBER3
#define myADC0_FORCE_Iout2 ADC_FORCE_SOC3
#define myADC0_SAMPLE_WINDOW_Iout2 57.41
#define myADC0_TRIGGER_SOURCE_Iout2 ADC_TRIGGER_EPWM3_SOCB
#define myADC0_CHANNEL_Iout2 ADC_CH_ADCIN6
void myADC0_init();

#define myADC1_BASE ADCC_BASE
#define myADC1_RESULT_BASE ADCCRESULT_BASE
#define myADC1_Il ADC_SOC_NUMBER0
#define myADC1_FORCE_Il ADC_FORCE_SOC0
#define myADC1_SAMPLE_WINDOW_Il 58.66
#define myADC1_TRIGGER_SOURCE_Il ADC_TRIGGER_EPWM3_SOCA
#define myADC1_CHANNEL_Il ADC_CH_ADCIN1
#define myADC1_Vout1 ADC_SOC_NUMBER1
#define myADC1_FORCE_Vout1 ADC_FORCE_SOC1
#define myADC1_SAMPLE_WINDOW_Vout1 59.94
#define myADC1_TRIGGER_SOURCE_Vout1 ADC_TRIGGER_EPWM3_SOCA
#define myADC1_CHANNEL_Vout1 ADC_CH_ADCIN14
#define myADC1_Vout2 ADC_SOC_NUMBER2
#define myADC1_FORCE_Vout2 ADC_FORCE_SOC2
#define myADC1_SAMPLE_WINDOW_Vout2 59.94
#define myADC1_TRIGGER_SOURCE_Vout2 ADC_TRIGGER_EPWM3_SOCB
#define myADC1_CHANNEL_Vout2 ADC_CH_ADCIN14
void myADC1_init();


//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// CLA Configurations
//
//*****************************************************************************
#define myCLA0_BASE CLA1_BASE

//
// The following are symbols defined in the CLA assembly code
// Including them in the shared header file makes them global
// and the main CPU can make use of them.
//
__attribute__((interrupt)) void Cla1Task1();
void myCLA0_init();


//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
#define myCPUTIMER0_BASE CPUTIMER0_BASE
void myCPUTIMER0_init();

//*****************************************************************************
//
// DMA Configurations
//
//*****************************************************************************
extern const void *ADCC0_Result_base;
extern const void *ADCC0_results_add;
#define myDMA0_BASE DMA_CH1_BASE 
#define myDMA0_BURSTSIZE 3U
#define myDMA0_TRANSFERSIZE 2U
void myDMA0_init();
extern const void *ADCA0_Result_base;
extern const void *ADCA0_results_add;
#define myDMA1_BASE DMA_CH2_BASE 
#define myDMA1_BURSTSIZE 4U
#define myDMA1_TRANSFERSIZE 2U
void myDMA1_init();

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define ControlPWM_BASE EPWM1_BASE
#define ControlPWM_TBPRD 1000
#define ControlPWM_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define ControlPWM_TBPHS 0
#define ControlPWM_CMPA 500
#define ControlPWM_CMPB 999
#define ControlPWM_CMPC 0
#define ControlPWM_CMPD 0
#define ControlPWM_DBRED 20
#define ControlPWM_DBFED 20
#define ControlPWM_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define ControlPWM_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define ControlPWM_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
// ControlPWM Configuration Template
void ePWMConfigurationTemplate(uint32_t base);
#define ControlPWM_fixed_fsw_BASE EPWM2_BASE
#define ControlPWM_fixed_fsw_TBPRD 1000
#define ControlPWM_fixed_fsw_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define ControlPWM_fixed_fsw_TBPHS 0
#define ControlPWM_fixed_fsw_CMPA 500
#define ControlPWM_fixed_fsw_CMPB 999
#define ControlPWM_fixed_fsw_CMPC 0
#define ControlPWM_fixed_fsw_CMPD 0
#define ControlPWM_fixed_fsw_DBRED 20
#define ControlPWM_fixed_fsw_DBFED 20
#define ControlPWM_fixed_fsw_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define ControlPWM_fixed_fsw_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define ControlPWM_fixed_fsw_INTERRUPT_SOURCE EPWM_INT_TBCTR_U_CMPB
#define ControlPWM_2fsw_BASE EPWM3_BASE
#define ControlPWM_2fsw_TBPRD 500
#define ControlPWM_2fsw_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define ControlPWM_2fsw_TBPHS 0
#define ControlPWM_2fsw_CMPA 250
#define ControlPWM_2fsw_CMPB 499
#define ControlPWM_2fsw_CMPC 0
#define ControlPWM_2fsw_CMPD 0
#define ControlPWM_2fsw_DBRED 20
#define ControlPWM_2fsw_DBFED 20
#define ControlPWM_2fsw_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define ControlPWM_2fsw_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define ControlPWM_2fsw_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define debug_pin 33
void debug_pin_init();
#define transient_det_pin 12
void transient_det_pin_init();
#define tz_pin 16
void tz_pin_init();
#define tz_clear_pin 11
void tz_clear_pin_init();

//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
#define myINPUTXBARINPUT0_SOURCE 12
#define myINPUTXBARINPUT0_INPUT XBAR_INPUT4
void myINPUTXBARINPUT0_init();

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************

// Interrupt Settings for INT_myCLA01
#define INT_myCLA01 INT_CLA1_1
#define INT_myCLA01_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP11
extern __interrupt void cla1Isr1(void);

// Interrupt Settings for INT_myDMA1
#define INT_myDMA1 INT_DMA_CH2
#define INT_myDMA1_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP7
extern __interrupt void INT_myDMA1_ISR(void);

// Interrupt Settings for INT_ControlPWM_fixed_fsw
#define INT_ControlPWM_fixed_fsw INT_EPWM2
#define INT_ControlPWM_fixed_fsw_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP3
extern __interrupt void INT_ControlPWM_fixed_fsw_ISR(void);

// Interrupt Settings for INT_transient_det_pin_XINT
#define INT_transient_det_pin_XINT INT_XINT1
#define INT_transient_det_pin_XINT_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_transient_det_pin_XINT_ISR(void);

//*****************************************************************************
//
// MEMCFG Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// XINT Configurations
//
//*****************************************************************************
#define transient_det_pin_XINT GPIO_INT_XINT1
#define transient_det_pin_XINT_TYPE GPIO_INT_TYPE_RISING_EDGE
void transient_det_pin_XINT_init();

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	ADC_init();
void	ASYSCTL_init();
void	CLA_init();
void	CPUTIMER_init();
void	DMA_init();
void	EPWM_init();
void	GPIO_init();
void	INPUTXBAR_init();
void	INTERRUPT_init();
void	MEMCFG_init();
void	SYNC_init();
void	XINT_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
