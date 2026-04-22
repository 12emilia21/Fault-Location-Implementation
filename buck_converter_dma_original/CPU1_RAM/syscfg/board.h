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
// EPWM2 -> ControlPWM_2fsw Pinmux
//
//
// EPWM2_A - GPIO Settings
//
#define GPIO_PIN_EPWM2_A 2
#define ControlPWM_2fsw_EPWMA_GPIO 2
#define ControlPWM_2fsw_EPWMA_PIN_CONFIG GPIO_2_EPWM2_A
//
// EPWM2_B - GPIO Settings
//
#define GPIO_PIN_EPWM2_B 3
#define ControlPWM_2fsw_EPWMB_GPIO 3
#define ControlPWM_2fsw_EPWMB_PIN_CONFIG GPIO_3_EPWM2_B
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
#define trigger_ls_GPIO_PIN_CONFIG GPIO_16_GPIO16
//
// GPIO17 - GPIO Settings
//
#define CLA_test_GPIO_PIN_CONFIG GPIO_17_GPIO17

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
#define myADC0_BASE ADCA_BASE
#define myADC0_RESULT_BASE ADCARESULT_BASE
#define myADC0_Iin1 ADC_SOC_NUMBER0
#define myADC0_FORCE_Iin1 ADC_FORCE_SOC0
#define myADC0_SAMPLE_WINDOW_Iin1 55.1
#define myADC0_TRIGGER_SOURCE_Iin1 ADC_TRIGGER_EPWM2_SOCA
#define myADC0_CHANNEL_Iin1 ADC_CH_ADCIN0
#define myADC0_Iin2 ADC_SOC_NUMBER1
#define myADC0_FORCE_Iin2 ADC_FORCE_SOC1
#define myADC0_SAMPLE_WINDOW_Iin2 55.1
#define myADC0_TRIGGER_SOURCE_Iin2 ADC_TRIGGER_EPWM2_SOCA
#define myADC0_CHANNEL_Iin2 ADC_CH_ADCIN0
void myADC0_init();

#define myADC1_BASE ADCC_BASE
#define myADC1_RESULT_BASE ADCCRESULT_BASE
#define myADC1_Vo1 ADC_SOC_NUMBER0
#define myADC1_FORCE_Vo1 ADC_FORCE_SOC0
#define myADC1_SAMPLE_WINDOW_Vo1 59.94
#define myADC1_TRIGGER_SOURCE_Vo1 ADC_TRIGGER_EPWM2_SOCA
#define myADC1_CHANNEL_Vo1 ADC_CH_ADCIN14
#define myADC1_Vo2 ADC_SOC_NUMBER1
#define myADC1_FORCE_Vo2 ADC_FORCE_SOC1
#define myADC1_SAMPLE_WINDOW_Vo2 59.94
#define myADC1_TRIGGER_SOURCE_Vo2 ADC_TRIGGER_EPWM2_SOCA
#define myADC1_CHANNEL_Vo2 ADC_CH_ADCIN14
#define myADC1_Vin1 ADC_SOC_NUMBER2
#define myADC1_FORCE_Vin1 ADC_FORCE_SOC2
#define myADC1_SAMPLE_WINDOW_Vin1 59.03
#define myADC1_TRIGGER_SOURCE_Vin1 ADC_TRIGGER_EPWM2_SOCA
#define myADC1_CHANNEL_Vin1 ADC_CH_ADCIN5
#define myADC1_Vin2 ADC_SOC_NUMBER3
#define myADC1_FORCE_Vin2 ADC_FORCE_SOC3
#define myADC1_SAMPLE_WINDOW_Vin2 59.03
#define myADC1_TRIGGER_SOURCE_Vin2 ADC_TRIGGER_EPWM2_SOCA
#define myADC1_CHANNEL_Vin2 ADC_CH_ADCIN5
#define myADC1_Il1 ADC_SOC_NUMBER4
#define myADC1_FORCE_Il1 ADC_FORCE_SOC4
#define myADC1_SAMPLE_WINDOW_Il1 59.11
#define myADC1_TRIGGER_SOURCE_Il1 ADC_TRIGGER_EPWM2_SOCA
#define myADC1_CHANNEL_Il1 ADC_CH_ADCIN3
#define myADC1_Il2 ADC_SOC_NUMBER5
#define myADC1_FORCE_Il2 ADC_FORCE_SOC5
#define myADC1_SAMPLE_WINDOW_Il2 59.11
#define myADC1_TRIGGER_SOURCE_Il2 ADC_TRIGGER_EPWM2_SOCA
#define myADC1_CHANNEL_Il2 ADC_CH_ADCIN3
void myADC1_init();

#define myADC2_BASE ADCB_BASE
#define myADC2_RESULT_BASE ADCBRESULT_BASE
#define myADC2_Io1 ADC_SOC_NUMBER0
#define myADC2_FORCE_Io1 ADC_FORCE_SOC0
#define myADC2_SAMPLE_WINDOW_Io1 56.73
#define myADC2_TRIGGER_SOURCE_Io1 ADC_TRIGGER_EPWM2_SOCA
#define myADC2_CHANNEL_Io1 ADC_CH_ADCIN6
#define myADC2_Io2 ADC_SOC_NUMBER1
#define myADC2_FORCE_Io2 ADC_FORCE_SOC1
#define myADC2_SAMPLE_WINDOW_Io2 56.73
#define myADC2_TRIGGER_SOURCE_Io2 ADC_TRIGGER_EPWM2_SOCA
#define myADC2_CHANNEL_Io2 ADC_CH_ADCIN6
void myADC2_init();


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
__attribute__((interrupt)) void Cla1Task2();
void myCLA0_init();


//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
#define alg_timer_BASE CPUTIMER0_BASE
void alg_timer_init();

//*****************************************************************************
//
// DMA Configurations
//
//*****************************************************************************
extern const void *ADCC0_Result_base;
extern const void *ADCC0_results_add;
#define myDMA0_BASE DMA_CH1_BASE 
#define myDMA0_BURSTSIZE 6U
#define myDMA0_TRANSFERSIZE 1U
void myDMA0_init();
extern const void *ADCA0_Result_base;
extern const void *ADCA0_results_add;
#define myDMA1_BASE DMA_CH2_BASE 
#define myDMA1_BURSTSIZE 2U
#define myDMA1_TRANSFERSIZE 1U
void myDMA1_init();
extern const void *ADCB0_Result_base;
extern const void *ADCB0_results_add;
#define myDMA2_BASE DMA_CH3_BASE 
#define myDMA2_BURSTSIZE 2U
#define myDMA2_TRANSFERSIZE 1U
void myDMA2_init();
extern const void *VO_data_source;
extern const void *VO_data_dest;
#define myDMA3_BASE DMA_CH4_BASE 
#define myDMA3_BURSTSIZE 2U
#define myDMA3_TRANSFERSIZE 127U
void myDMA3_init();
extern const void *IO_data_source;
extern const void *IO_data_dest;
#define myDMA4_BASE DMA_CH5_BASE 
#define myDMA4_BURSTSIZE 2U
#define myDMA4_TRANSFERSIZE 127U
void myDMA4_init();

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define ControlPWM_BASE EPWM1_BASE
#define ControlPWM_TBPRD 5000
#define ControlPWM_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define ControlPWM_TBPHS 0
#define ControlPWM_CMPA 2500
#define ControlPWM_CMPB 4999
#define ControlPWM_CMPC 0
#define ControlPWM_CMPD 0
#define ControlPWM_DBRED 20
#define ControlPWM_DBFED 20
#define ControlPWM_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define ControlPWM_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define ControlPWM_INTERRUPT_SOURCE EPWM_INT_TBCTR_U_CMPB
// ControlPWM Configuration Template
void ePWMConfigurationTemplate(uint32_t base);
#define ControlPWM_2fsw_BASE EPWM2_BASE
#define ControlPWM_2fsw_TBPRD 2500
#define ControlPWM_2fsw_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define ControlPWM_2fsw_TBPHS 0
#define ControlPWM_2fsw_CMPA 1250
#define ControlPWM_2fsw_CMPB 2499
#define ControlPWM_2fsw_CMPC 0
#define ControlPWM_2fsw_CMPD 0
#define ControlPWM_2fsw_DBRED 10
#define ControlPWM_2fsw_DBFED 10
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
#define trigger_ls 16
void trigger_ls_init();
#define CLA_test 17
void CLA_test_init();

//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
#define myINPUTXBARINPUT0_SOURCE 12
#define myINPUTXBARINPUT0_INPUT XBAR_INPUT4
void myINPUTXBARINPUT0_init();
#define myINPUTXBARINPUT1_SOURCE 16
#define myINPUTXBARINPUT1_INPUT XBAR_INPUT5
void myINPUTXBARINPUT1_init();
#define myINPUTXBARINPUT2_SOURCE 17
#define myINPUTXBARINPUT2_INPUT XBAR_INPUT13
void myINPUTXBARINPUT2_init();

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************

// Interrupt Settings for INT_myCLA01
#define INT_myCLA01 INT_CLA1_1
#define INT_myCLA01_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP11
extern __interrupt void cla1Isr1(void);

// Interrupt Settings for INT_myDMA0
#define INT_myDMA0 INT_DMA_CH1
#define INT_myDMA0_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP7
extern __interrupt void INT_myDMA0_ISR(void);

// Interrupt Settings for INT_myDMA3
#define INT_myDMA3 INT_DMA_CH4
#define INT_myDMA3_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP7
extern __interrupt void INT_myDMA3_ISR(void);

// Interrupt Settings for INT_myDMA4
#define INT_myDMA4 INT_DMA_CH5
#define INT_myDMA4_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP7
extern __interrupt void INT_myDMA4_ISR(void);

// Interrupt Settings for INT_ControlPWM
#define INT_ControlPWM INT_EPWM1
#define INT_ControlPWM_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP3
extern __interrupt void INT_ControlPWM_ISR(void);

// Interrupt Settings for INT_transient_det_pin_XINT
#define INT_transient_det_pin_XINT INT_XINT1
#define INT_transient_det_pin_XINT_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_transient_det_pin_XINT_ISR(void);

// Interrupt Settings for INT_trigger_ls_XINT
#define INT_trigger_ls_XINT INT_XINT2
#define INT_trigger_ls_XINT_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_trigger_ls_XINT_ISR(void);

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
#define trigger_ls_XINT GPIO_INT_XINT2
#define trigger_ls_XINT_TYPE GPIO_INT_TYPE_RISING_EDGE
void trigger_ls_XINT_init();

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
