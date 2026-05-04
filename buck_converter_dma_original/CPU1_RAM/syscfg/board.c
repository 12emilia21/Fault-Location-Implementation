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

#include "board.h"

//*****************************************************************************
//
// Board Configurations
// Initializes the rest of the modules. 
// Call this function in your application if you wish to do all module 
// initialization.
// If you wish to not use some of the initializations, instead of the 
// Board_init use the individual Module_inits
//
//*****************************************************************************
void Board_init()
{
	EALLOW;

	PinMux_init();
	INPUTXBAR_init();
	SYNC_init();
	ASYSCTL_init();
	CLA_init();
	MEMCFG_init();
	ADC_init();
	DMA_init();
	EPWM_init();
	GPIO_init();
	XINT_init();
	INTERRUPT_init();

	EDIS;
}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
	//
	// PinMux for modules assigned to CPU1
	//
	
	//
	// EPWM1 -> ControlPWM Pinmux
	//
	GPIO_setPinConfig(ControlPWM_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(ControlPWM_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(ControlPWM_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(ControlPWM_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(ControlPWM_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(ControlPWM_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM2 -> ControlPWM_fixed_fsw Pinmux
	//
	GPIO_setPinConfig(ControlPWM_fixed_fsw_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(ControlPWM_fixed_fsw_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(ControlPWM_fixed_fsw_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(ControlPWM_fixed_fsw_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(ControlPWM_fixed_fsw_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(ControlPWM_fixed_fsw_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM3 -> ControlPWM_2fsw Pinmux
	//
	GPIO_setPinConfig(ControlPWM_2fsw_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(ControlPWM_2fsw_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(ControlPWM_2fsw_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(ControlPWM_2fsw_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(ControlPWM_2fsw_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(ControlPWM_2fsw_EPWMB_GPIO, GPIO_QUAL_SYNC);

	// GPIO33 -> debug_pin Pinmux
	GPIO_setPinConfig(GPIO_33_GPIO33);
	// GPIO12 -> transient_det_pin Pinmux
	GPIO_setPinConfig(GPIO_12_GPIO12);

}

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
void ADC_init(){
	myADC0_init();
	myADC1_init();
	myADC2_init();
}

void myADC0_init(){
	//
	// ADC Initialization: Write ADC configurations and power up the ADC
	//
	// Configures the ADC module's offset trim
	//
	ADC_setOffsetTrimAll(ADC_REFERENCE_INTERNAL,ADC_REFERENCE_3_3V);
	//
	// Configures the analog-to-digital converter module prescaler.
	//
	ADC_setPrescaler(myADC0_BASE, ADC_CLK_DIV_1_0);
	//
	// Sets the timing of the end-of-conversion pulse
	//
	ADC_setInterruptPulseMode(myADC0_BASE, ADC_PULSE_END_OF_CONV);
	//
	// Powers up the analog-to-digital converter core.
	//
	ADC_enableConverter(myADC0_BASE);
	//
	// Delay for 1ms to allow ADC time to power up
	//
	DEVICE_DELAY_US(5000);
	//
	// SOC Configuration: Setup ADC EPWM channel and trigger settings
	//
	// Disables SOC burst mode.
	//
	ADC_disableBurstMode(myADC0_BASE);
	//
	// Sets the priority mode of the SOCs.
	//
	ADC_setSOCPriority(myADC0_BASE, ADC_PRI_ALL_ROUND_ROBIN);
	//
	// Start of Conversion 0 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 0
	//	  	Trigger			: ADC_TRIGGER_EPWM2_SOCA
	//	  	Channel			: ADC_CH_ADCIN0
	//	 	Sample Window	: 6 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM2_SOCA, ADC_CH_ADCIN0, 6U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER0, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 1 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 1
	//	  	Trigger			: ADC_TRIGGER_EPWM2_SOCB
	//	  	Channel			: ADC_CH_ADCIN0
	//	 	Sample Window	: 6 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_EPWM2_SOCB, ADC_CH_ADCIN0, 6U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER1, ADC_INT_SOC_TRIGGER_NONE);
	//
	// ADC Interrupt 1 Configuration
	// 		SOC/EOC number	: 1
	// 		Interrupt Source: enabled
	//		Continuous Mode	: enabled
	//
	ADC_setInterruptSource(myADC0_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER1);
	ADC_enableInterrupt(myADC0_BASE, ADC_INT_NUMBER1);
	ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);
	ADC_enableContinuousMode(myADC0_BASE, ADC_INT_NUMBER1);
}
void myADC1_init(){
	//
	// ADC Initialization: Write ADC configurations and power up the ADC
	//
	// Configures the ADC module's offset trim
	//
	ADC_setOffsetTrimAll(ADC_REFERENCE_INTERNAL,ADC_REFERENCE_3_3V);
	//
	// Configures the analog-to-digital converter module prescaler.
	//
	ADC_setPrescaler(myADC1_BASE, ADC_CLK_DIV_1_0);
	//
	// Sets the timing of the end-of-conversion pulse
	//
	ADC_setInterruptPulseMode(myADC1_BASE, ADC_PULSE_END_OF_CONV);
	//
	// Powers up the analog-to-digital converter core.
	//
	ADC_enableConverter(myADC1_BASE);
	//
	// Delay for 1ms to allow ADC time to power up
	//
	DEVICE_DELAY_US(5000);
	//
	// SOC Configuration: Setup ADC EPWM channel and trigger settings
	//
	// Disables SOC burst mode.
	//
	ADC_disableBurstMode(myADC1_BASE);
	//
	// Sets the priority mode of the SOCs.
	//
	ADC_setSOCPriority(myADC1_BASE, ADC_PRI_THRU_SOC5_HIPRI);
	//
	// Start of Conversion 0 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 0
	//	  	Trigger			: ADC_TRIGGER_EPWM3_SOCA
	//	  	Channel			: ADC_CH_ADCIN5
	//	 	Sample Window	: 6 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC1_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN5, 6U);
	ADC_setInterruptSOCTrigger(myADC1_BASE, ADC_SOC_NUMBER0, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 1 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 1
	//	  	Trigger			: ADC_TRIGGER_EPWM3_SOCA
	//	  	Channel			: ADC_CH_ADCIN3
	//	 	Sample Window	: 6 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC1_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN3, 6U);
	ADC_setInterruptSOCTrigger(myADC1_BASE, ADC_SOC_NUMBER1, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 2 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 2
	//	  	Trigger			: ADC_TRIGGER_EPWM3_SOCA
	//	  	Channel			: ADC_CH_ADCIN14
	//	 	Sample Window	: 6 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC1_BASE, ADC_SOC_NUMBER2, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN14, 6U);
	ADC_setInterruptSOCTrigger(myADC1_BASE, ADC_SOC_NUMBER2, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 3 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 3
	//	  	Trigger			: ADC_TRIGGER_EPWM3_SOCB
	//	  	Channel			: ADC_CH_ADCIN14
	//	 	Sample Window	: 6 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC1_BASE, ADC_SOC_NUMBER3, ADC_TRIGGER_EPWM3_SOCB, ADC_CH_ADCIN14, 6U);
	ADC_setInterruptSOCTrigger(myADC1_BASE, ADC_SOC_NUMBER3, ADC_INT_SOC_TRIGGER_NONE);
	//
	// ADC Interrupt 1 Configuration
	// 		SOC/EOC number	: 3
	// 		Interrupt Source: enabled
	//		Continuous Mode	: enabled
	//
	ADC_setInterruptSource(myADC1_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER3);
	ADC_enableInterrupt(myADC1_BASE, ADC_INT_NUMBER1);
	ADC_clearInterruptStatus(myADC1_BASE, ADC_INT_NUMBER1);
	ADC_enableContinuousMode(myADC1_BASE, ADC_INT_NUMBER1);
}
void myADC2_init(){
	//
	// ADC Initialization: Write ADC configurations and power up the ADC
	//
	// Configures the ADC module's offset trim
	//
	ADC_setOffsetTrimAll(ADC_REFERENCE_INTERNAL,ADC_REFERENCE_3_3V);
	//
	// Configures the analog-to-digital converter module prescaler.
	//
	ADC_setPrescaler(myADC2_BASE, ADC_CLK_DIV_1_0);
	//
	// Sets the timing of the end-of-conversion pulse
	//
	ADC_setInterruptPulseMode(myADC2_BASE, ADC_PULSE_END_OF_CONV);
	//
	// Powers up the analog-to-digital converter core.
	//
	ADC_enableConverter(myADC2_BASE);
	//
	// Delay for 1ms to allow ADC time to power up
	//
	DEVICE_DELAY_US(5000);
	//
	// SOC Configuration: Setup ADC EPWM channel and trigger settings
	//
	// Disables SOC burst mode.
	//
	ADC_disableBurstMode(myADC2_BASE);
	//
	// Sets the priority mode of the SOCs.
	//
	ADC_setSOCPriority(myADC2_BASE, ADC_PRI_ALL_ROUND_ROBIN);
	//
	// Start of Conversion 0 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 0
	//	  	Trigger			: ADC_TRIGGER_EPWM3_SOCA
	//	  	Channel			: ADC_CH_ADCIN6
	//	 	Sample Window	: 6 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC2_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN6, 6U);
	ADC_setInterruptSOCTrigger(myADC2_BASE, ADC_SOC_NUMBER0, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 1 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 1
	//	  	Trigger			: ADC_TRIGGER_EPWM3_SOCB
	//	  	Channel			: ADC_CH_ADCIN6
	//	 	Sample Window	: 6 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC2_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_EPWM3_SOCB, ADC_CH_ADCIN6, 6U);
	ADC_setInterruptSOCTrigger(myADC2_BASE, ADC_SOC_NUMBER1, ADC_INT_SOC_TRIGGER_NONE);
	//
	// ADC Interrupt 1 Configuration
	// 		SOC/EOC number	: 1
	// 		Interrupt Source: enabled
	//		Continuous Mode	: enabled
	//
	ADC_setInterruptSource(myADC2_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER1);
	ADC_enableInterrupt(myADC2_BASE, ADC_INT_NUMBER1);
	ADC_clearInterruptStatus(myADC2_BASE, ADC_INT_NUMBER1);
	ADC_enableContinuousMode(myADC2_BASE, ADC_INT_NUMBER1);
}

//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************
void ASYSCTL_init(){
	//
	// asysctl initialization
	//
	// Disables the temperature sensor output to the ADC.
	//
	ASysCtl_disableTemperatureSensor();
	//
	// Set the analog voltage reference selection to internal.
	//
	ASysCtl_setAnalogReferenceInternal( ASYSCTL_VREFHIA | ASYSCTL_VREFHIB | ASYSCTL_VREFHIC );
	//
	// Set the internal analog voltage reference selection to 1.65V.
	//
	ASysCtl_setAnalogReference1P65( ASYSCTL_VREFHIA | ASYSCTL_VREFHIB | ASYSCTL_VREFHIC );
}
//*****************************************************************************
//
// CLA Configurations
//
//*****************************************************************************

void myCLA0_init(){
	//
    // Configure all CLA task vectors
    // On Type-1 and Type-2 CLAs the MVECT registers accept full 16-bit task addresses as
    // opposed to offsets used on older Type-0 CLAs
    //
#pragma diag_suppress=770
    //
    // CLA Task 1
    //
    CLA_mapTaskVector(myCLA0_BASE, CLA_MVECT_1, (uint16_t)&Cla1Task1);
    CLA_setTriggerSource(CLA_TASK_1, CLA_TRIGGER_XINT1);
#pragma diag_warning=770
	//
    // Enable the IACK instruction to start a task on CLA in software
    // for all  8 CLA tasks. Also, globally enable all 8 tasks (or a
    // subset of tasks) by writing to their respective bits in the
    // MIER register
    //
	CLA_enableIACK(myCLA0_BASE);
    CLA_enableTasks(myCLA0_BASE, CLA_TASKFLAG_1 );
}


void CLA_init()
{
#ifdef _FLASH
#ifndef CMDTOOL // Linker command tool is not used

    extern uint32_t Cla1ProgRunStart, Cla1ProgLoadStart, Cla1ProgLoadSize;
    extern uint32_t Cla1ConstRunStart, Cla1ConstLoadStart, Cla1ConstLoadSize;

    //
    // Copy the program and constants from FLASH to RAM before configuring
    // the CLA
    //
    memcpy((uint32_t *)&Cla1ProgRunStart, (uint32_t *)&Cla1ProgLoadStart,
           (uint32_t)&Cla1ProgLoadSize);
    memcpy((uint32_t *)&Cla1ConstRunStart, (uint32_t *)&Cla1ConstLoadStart,
        (uint32_t)&Cla1ConstLoadSize );


#endif //CMDTOOL
#endif //_FLASH

	myCLA0_init();
}

//*****************************************************************************
//
// DMA Configurations
//
//*****************************************************************************
void DMA_init(){
    DMA_initController();
	myDMA0_init();
	myDMA1_init();
	myDMA2_init();
}

void myDMA0_init(){
    DMA_setEmulationMode(DMA_EMULATION_STOP);
    DMA_configAddresses(myDMA0_BASE, ADCC0_results_add, ADCC0_Result_base);
    DMA_configBurst(myDMA0_BASE, 4U, 1, 1);
    DMA_configTransfer(myDMA0_BASE, 2U, -3, 1);
    DMA_configWrap(myDMA0_BASE, 65535U, 0, 2U, -7);
    DMA_configMode(myDMA0_BASE, DMA_TRIGGER_ADCC1, DMA_CFG_ONESHOT_DISABLE | DMA_CFG_CONTINUOUS_ENABLE | DMA_CFG_SIZE_16BIT);
    DMA_enableTrigger(myDMA0_BASE);
    DMA_startChannel(myDMA0_BASE);
}
void myDMA1_init(){
    DMA_setEmulationMode(DMA_EMULATION_STOP);
    DMA_configAddresses(myDMA1_BASE, ADCA0_results_add, ADCA0_Result_base);
    DMA_configBurst(myDMA1_BASE, 2U, 1, 1);
    DMA_configTransfer(myDMA1_BASE, 1U, -1, -1);
    DMA_configWrap(myDMA1_BASE, 65535U, 0, 65535U, 0);
    DMA_configMode(myDMA1_BASE, DMA_TRIGGER_ADCA1, DMA_CFG_ONESHOT_DISABLE | DMA_CFG_CONTINUOUS_ENABLE | DMA_CFG_SIZE_16BIT);
    DMA_enableTrigger(myDMA1_BASE);
    DMA_startChannel(myDMA1_BASE);
}
void myDMA2_init(){
    DMA_setEmulationMode(DMA_EMULATION_STOP);
    DMA_configAddresses(myDMA2_BASE, ADCB0_results_add, ADCB0_Result_base);
    DMA_configBurst(myDMA2_BASE, 2U, 1, 1);
    DMA_configTransfer(myDMA2_BASE, 2U, -1, 1);
    DMA_configWrap(myDMA2_BASE, 65535U, 0, 2U, -3);
    DMA_configMode(myDMA2_BASE, DMA_TRIGGER_ADCB1, DMA_CFG_ONESHOT_DISABLE | DMA_CFG_CONTINUOUS_ENABLE | DMA_CFG_SIZE_16BIT);
    DMA_enableTrigger(myDMA2_BASE);
    DMA_startChannel(myDMA2_BASE);
}

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init(){
    HRPWM_setEmulationMode(ControlPWM_BASE, EPWM_EMULATION_FREE_RUN);	
    HRPWM_setClockPrescaler(ControlPWM_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(ControlPWM_BASE, 5000);	
    HRPWM_enableGlobalLoadRegisters(ControlPWM_BASE, EPWM_GL_REGISTER_TBPRD_TBPRDHR);	
    HRPWM_setTimeBaseCounter(ControlPWM_BASE, 0);	
    HRPWM_setTimeBaseCounterMode(ControlPWM_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    HRPWM_setCountModeAfterSync(ControlPWM_BASE, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    HRPWM_disablePhaseShiftLoad(ControlPWM_BASE);	
    HRPWM_setPhaseShift(ControlPWM_BASE, 0);	
    HRPWM_setSyncOutPulseMode(ControlPWM_BASE, EPWM_SYNC_OUT_PULSE_ON_COUNTER_ZERO);	
    EPWM_setCounterCompareValue(ControlPWM_BASE, EPWM_COUNTER_COMPARE_A, 2500);	
    HRPWM_disableCounterCompareShadowLoadMode(ControlPWM_BASE, EPWM_COUNTER_COMPARE_A);	
    HRPWM_setCounterCompareShadowLoadMode(ControlPWM_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(ControlPWM_BASE, EPWM_COUNTER_COMPARE_B, 4999);	
    HRPWM_disableCounterCompareShadowLoadMode(ControlPWM_BASE, EPWM_COUNTER_COMPARE_B);	
    HRPWM_setCounterCompareShadowLoadMode(ControlPWM_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    HRPWM_enableGlobalLoadRegisters(ControlPWM_BASE, EPWM_GL_REGISTER_AQCSFRC);	
    HRPWM_setActionQualifierContSWForceShadowMode(ControlPWM_BASE, EPWM_AQ_SW_IMMEDIATE_LOAD);	
    HRPWM_setActionQualifierT1TriggerSource(ControlPWM_BASE, EPWM_AQ_TRIGGER_EVENT_TRIG_EPWM_SYNCIN);	
    HRPWM_setActionQualifierT2TriggerSource(ControlPWM_BASE, EPWM_AQ_TRIGGER_EVENT_TRIG_EPWM_SYNCIN);	
    HRPWM_setActionQualifierAction(ControlPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    HRPWM_setActionQualifierAction(ControlPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    HRPWM_setActionQualifierAction(ControlPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    HRPWM_setActionQualifierAction(ControlPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    HRPWM_setActionQualifierAction(ControlPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    HRPWM_setActionQualifierAction(ControlPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    HRPWM_setActionQualifierAction(ControlPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_T1_COUNT_UP);	
    HRPWM_setActionQualifierAction(ControlPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    HRPWM_setActionQualifierAction(ControlPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    HRPWM_setActionQualifierAction(ControlPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    HRPWM_setActionQualifierAction(ControlPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    HRPWM_setActionQualifierAction(ControlPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    HRPWM_setActionQualifierAction(ControlPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    HRPWM_setActionQualifierAction(ControlPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_T1_COUNT_UP);	
    HRPWM_setDeadBandDelayPolarity(ControlPWM_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    HRPWM_setDeadBandDelayMode(ControlPWM_BASE, EPWM_DB_RED, true);	
    HRPWM_setRisingEdgeDelayCount(ControlPWM_BASE, 20);	
    HRPWM_setDeadBandDelayMode(ControlPWM_BASE, EPWM_DB_FED, true);	
    HRPWM_setFallingEdgeDelayCount(ControlPWM_BASE, 20);	
    HRPWM_enableInterrupt(ControlPWM_BASE);	
    HRPWM_setInterruptSource(ControlPWM_BASE, EPWM_INT_TBCTR_U_CMPB);	
    HRPWM_setInterruptEventCount(ControlPWM_BASE, 1);	
    HRPWM_forceInterruptEventCountInit(ControlPWM_BASE);	
    HRPWM_enableADCTrigger(ControlPWM_BASE, EPWM_SOC_A);	
    HRPWM_setADCTriggerSource(ControlPWM_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_PERIOD);	
    HRPWM_setADCTriggerEventPrescale(ControlPWM_BASE, EPWM_SOC_A, 1);	
    HRPWM_enableADCTrigger(ControlPWM_BASE, EPWM_SOC_B);	
    HRPWM_setADCTriggerSource(ControlPWM_BASE, EPWM_SOC_B, EPWM_SOC_TBCTR_ZERO);	
    HRPWM_setADCTriggerEventPrescale(ControlPWM_BASE, EPWM_SOC_B, 1);	
    HRPWM_enableAutoConversion(ControlPWM_BASE);	
    HRPWM_setEmulationMode(ControlPWM_fixed_fsw_BASE, EPWM_EMULATION_FREE_RUN);	
    HRPWM_setClockPrescaler(ControlPWM_fixed_fsw_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(ControlPWM_fixed_fsw_BASE, 5000);	
    HRPWM_enableGlobalLoadRegisters(ControlPWM_fixed_fsw_BASE, EPWM_GL_REGISTER_TBPRD_TBPRDHR);	
    HRPWM_setTimeBaseCounter(ControlPWM_fixed_fsw_BASE, 0);	
    HRPWM_setTimeBaseCounterMode(ControlPWM_fixed_fsw_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    HRPWM_setCountModeAfterSync(ControlPWM_fixed_fsw_BASE, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    HRPWM_disablePhaseShiftLoad(ControlPWM_fixed_fsw_BASE);	
    HRPWM_setPhaseShift(ControlPWM_fixed_fsw_BASE, 0);	
    HRPWM_setSyncOutPulseMode(ControlPWM_fixed_fsw_BASE, EPWM_SYNC_OUT_PULSE_ON_COUNTER_ZERO);	
    EPWM_setCounterCompareValue(ControlPWM_fixed_fsw_BASE, EPWM_COUNTER_COMPARE_A, 2500);	
    HRPWM_disableCounterCompareShadowLoadMode(ControlPWM_fixed_fsw_BASE, EPWM_COUNTER_COMPARE_A);	
    HRPWM_setCounterCompareShadowLoadMode(ControlPWM_fixed_fsw_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(ControlPWM_fixed_fsw_BASE, EPWM_COUNTER_COMPARE_B, 4999);	
    HRPWM_disableCounterCompareShadowLoadMode(ControlPWM_fixed_fsw_BASE, EPWM_COUNTER_COMPARE_B);	
    HRPWM_setCounterCompareShadowLoadMode(ControlPWM_fixed_fsw_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    HRPWM_enableGlobalLoadRegisters(ControlPWM_fixed_fsw_BASE, EPWM_GL_REGISTER_AQCSFRC);	
    HRPWM_setActionQualifierContSWForceShadowMode(ControlPWM_fixed_fsw_BASE, EPWM_AQ_SW_IMMEDIATE_LOAD);	
    HRPWM_setActionQualifierT1TriggerSource(ControlPWM_fixed_fsw_BASE, EPWM_AQ_TRIGGER_EVENT_TRIG_EPWM_SYNCIN);	
    HRPWM_setActionQualifierT2TriggerSource(ControlPWM_fixed_fsw_BASE, EPWM_AQ_TRIGGER_EVENT_TRIG_EPWM_SYNCIN);	
    HRPWM_setActionQualifierAction(ControlPWM_fixed_fsw_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    HRPWM_setActionQualifierAction(ControlPWM_fixed_fsw_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    HRPWM_setActionQualifierAction(ControlPWM_fixed_fsw_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    HRPWM_setActionQualifierAction(ControlPWM_fixed_fsw_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    HRPWM_setActionQualifierAction(ControlPWM_fixed_fsw_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    HRPWM_setActionQualifierAction(ControlPWM_fixed_fsw_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    HRPWM_setActionQualifierAction(ControlPWM_fixed_fsw_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_T1_COUNT_UP);	
    HRPWM_setActionQualifierAction(ControlPWM_fixed_fsw_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    HRPWM_setActionQualifierAction(ControlPWM_fixed_fsw_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    HRPWM_setActionQualifierAction(ControlPWM_fixed_fsw_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    HRPWM_setActionQualifierAction(ControlPWM_fixed_fsw_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    HRPWM_setActionQualifierAction(ControlPWM_fixed_fsw_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    HRPWM_setActionQualifierAction(ControlPWM_fixed_fsw_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    HRPWM_setActionQualifierAction(ControlPWM_fixed_fsw_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_T1_COUNT_UP);	
    HRPWM_setDeadBandDelayPolarity(ControlPWM_fixed_fsw_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    HRPWM_setDeadBandDelayMode(ControlPWM_fixed_fsw_BASE, EPWM_DB_RED, true);	
    HRPWM_setRisingEdgeDelayCount(ControlPWM_fixed_fsw_BASE, 20);	
    HRPWM_setDeadBandDelayMode(ControlPWM_fixed_fsw_BASE, EPWM_DB_FED, true);	
    HRPWM_setFallingEdgeDelayCount(ControlPWM_fixed_fsw_BASE, 20);	
    HRPWM_enableADCTrigger(ControlPWM_fixed_fsw_BASE, EPWM_SOC_A);	
    HRPWM_setADCTriggerSource(ControlPWM_fixed_fsw_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_PERIOD);	
    HRPWM_setADCTriggerEventPrescale(ControlPWM_fixed_fsw_BASE, EPWM_SOC_A, 1);	
    HRPWM_enableADCTrigger(ControlPWM_fixed_fsw_BASE, EPWM_SOC_B);	
    HRPWM_setADCTriggerSource(ControlPWM_fixed_fsw_BASE, EPWM_SOC_B, EPWM_SOC_TBCTR_ZERO);	
    HRPWM_setADCTriggerEventPrescale(ControlPWM_fixed_fsw_BASE, EPWM_SOC_B, 1);	
    HRPWM_enableAutoConversion(ControlPWM_fixed_fsw_BASE);	
    HRPWM_setEmulationMode(ControlPWM_2fsw_BASE, EPWM_EMULATION_FREE_RUN);	
    HRPWM_setClockPrescaler(ControlPWM_2fsw_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(ControlPWM_2fsw_BASE, 2500);	
    HRPWM_enableGlobalLoadRegisters(ControlPWM_2fsw_BASE, EPWM_GL_REGISTER_TBPRD_TBPRDHR);	
    HRPWM_setTimeBaseCounter(ControlPWM_2fsw_BASE, 0);	
    HRPWM_setTimeBaseCounterMode(ControlPWM_2fsw_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    HRPWM_setCountModeAfterSync(ControlPWM_2fsw_BASE, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    HRPWM_disablePhaseShiftLoad(ControlPWM_2fsw_BASE);	
    HRPWM_setPhaseShift(ControlPWM_2fsw_BASE, 0);	
    HRPWM_setSyncOutPulseMode(ControlPWM_2fsw_BASE, EPWM_SYNC_OUT_PULSE_ON_EPWMxSYNCIN);	
    EPWM_setCounterCompareValue(ControlPWM_2fsw_BASE, EPWM_COUNTER_COMPARE_A, 1250);	
    HRPWM_disableCounterCompareShadowLoadMode(ControlPWM_2fsw_BASE, EPWM_COUNTER_COMPARE_A);	
    HRPWM_setCounterCompareShadowLoadMode(ControlPWM_2fsw_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(ControlPWM_2fsw_BASE, EPWM_COUNTER_COMPARE_B, 2499);	
    HRPWM_disableCounterCompareShadowLoadMode(ControlPWM_2fsw_BASE, EPWM_COUNTER_COMPARE_B);	
    HRPWM_setCounterCompareShadowLoadMode(ControlPWM_2fsw_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    HRPWM_enableGlobalLoadRegisters(ControlPWM_2fsw_BASE, EPWM_GL_REGISTER_AQCSFRC);	
    HRPWM_setActionQualifierContSWForceShadowMode(ControlPWM_2fsw_BASE, EPWM_AQ_SW_IMMEDIATE_LOAD);	
    HRPWM_setActionQualifierT1TriggerSource(ControlPWM_2fsw_BASE, EPWM_AQ_TRIGGER_EVENT_TRIG_EPWM_SYNCIN);	
    HRPWM_setActionQualifierT2TriggerSource(ControlPWM_2fsw_BASE, EPWM_AQ_TRIGGER_EVENT_TRIG_EPWM_SYNCIN);	
    HRPWM_setActionQualifierAction(ControlPWM_2fsw_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    HRPWM_setActionQualifierAction(ControlPWM_2fsw_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    HRPWM_setActionQualifierAction(ControlPWM_2fsw_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    HRPWM_setActionQualifierAction(ControlPWM_2fsw_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    HRPWM_setActionQualifierAction(ControlPWM_2fsw_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    HRPWM_setActionQualifierAction(ControlPWM_2fsw_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    HRPWM_setActionQualifierAction(ControlPWM_2fsw_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_T1_COUNT_UP);	
    HRPWM_setActionQualifierAction(ControlPWM_2fsw_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    HRPWM_setActionQualifierAction(ControlPWM_2fsw_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    HRPWM_setActionQualifierAction(ControlPWM_2fsw_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    HRPWM_setActionQualifierAction(ControlPWM_2fsw_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    HRPWM_setActionQualifierAction(ControlPWM_2fsw_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    HRPWM_setActionQualifierAction(ControlPWM_2fsw_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    HRPWM_setDeadBandDelayPolarity(ControlPWM_2fsw_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    HRPWM_setDeadBandDelayMode(ControlPWM_2fsw_BASE, EPWM_DB_RED, true);	
    HRPWM_setRisingEdgeDelayCount(ControlPWM_2fsw_BASE, 10);	
    HRPWM_setDeadBandDelayMode(ControlPWM_2fsw_BASE, EPWM_DB_FED, true);	
    HRPWM_setFallingEdgeDelayCount(ControlPWM_2fsw_BASE, 10);	
    HRPWM_enableADCTrigger(ControlPWM_2fsw_BASE, EPWM_SOC_A);	
    HRPWM_setADCTriggerSource(ControlPWM_2fsw_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_ZERO);	
    HRPWM_setADCTriggerEventPrescale(ControlPWM_2fsw_BASE, EPWM_SOC_A, 1);	
    HRPWM_enableADCTrigger(ControlPWM_2fsw_BASE, EPWM_SOC_B);	
    HRPWM_setADCTriggerSource(ControlPWM_2fsw_BASE, EPWM_SOC_B, EPWM_SOC_TBCTR_ZERO);	
    HRPWM_setADCTriggerEventPrescale(ControlPWM_2fsw_BASE, EPWM_SOC_B, 1);	
    HRPWM_enableAutoConversion(ControlPWM_2fsw_BASE);	
}
// ControlPWM Configuration Template
void ePWMConfigurationTemplate(uint32_t base){
    HRPWM_setEmulationMode(base, EPWM_EMULATION_FREE_RUN);	
    HRPWM_setClockPrescaler(base, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(base, 5000);	
    HRPWM_enableGlobalLoadRegisters(base, EPWM_GL_REGISTER_TBPRD_TBPRDHR);	
    HRPWM_setTimeBaseCounter(base, 0);	
    HRPWM_setTimeBaseCounterMode(base, EPWM_COUNTER_MODE_UP_DOWN);	
    HRPWM_setCountModeAfterSync(base, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    HRPWM_disablePhaseShiftLoad(base);	
    HRPWM_setPhaseShift(base, 0);	
    HRPWM_setSyncOutPulseMode(base, EPWM_SYNC_OUT_PULSE_ON_COUNTER_ZERO);	
    EPWM_setCounterCompareValue(base, EPWM_COUNTER_COMPARE_A, 2500);	
    HRPWM_disableCounterCompareShadowLoadMode(base, EPWM_COUNTER_COMPARE_A);	
    HRPWM_setCounterCompareShadowLoadMode(base, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(base, EPWM_COUNTER_COMPARE_B, 4999);	
    HRPWM_disableCounterCompareShadowLoadMode(base, EPWM_COUNTER_COMPARE_B);	
    HRPWM_setCounterCompareShadowLoadMode(base, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    HRPWM_enableGlobalLoadRegisters(base, EPWM_GL_REGISTER_AQCSFRC);	
    HRPWM_setActionQualifierContSWForceShadowMode(base, EPWM_AQ_SW_IMMEDIATE_LOAD);	
    HRPWM_setActionQualifierT1TriggerSource(base, EPWM_AQ_TRIGGER_EVENT_TRIG_EPWM_SYNCIN);	
    HRPWM_setActionQualifierT2TriggerSource(base, EPWM_AQ_TRIGGER_EVENT_TRIG_EPWM_SYNCIN);	
    HRPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    HRPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    HRPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    HRPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    HRPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    HRPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    HRPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_T1_COUNT_UP);	
    HRPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    HRPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    HRPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    HRPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    HRPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    HRPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    HRPWM_setActionQualifierAction(base, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_T1_COUNT_UP);	
    HRPWM_setDeadBandDelayPolarity(base, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    HRPWM_setDeadBandDelayMode(base, EPWM_DB_RED, true);	
    HRPWM_setRisingEdgeDelayCount(base, 20);	
    HRPWM_setDeadBandDelayMode(base, EPWM_DB_FED, true);	
    HRPWM_setFallingEdgeDelayCount(base, 20);	
    HRPWM_enableInterrupt(base);	
    HRPWM_setInterruptSource(base, EPWM_INT_TBCTR_U_CMPB);	
    HRPWM_setInterruptEventCount(base, 1);	
    HRPWM_forceInterruptEventCountInit(base);	
    HRPWM_enableADCTrigger(base, EPWM_SOC_A);	
    HRPWM_setADCTriggerSource(base, EPWM_SOC_A, EPWM_SOC_TBCTR_PERIOD);	
    HRPWM_setADCTriggerEventPrescale(base, EPWM_SOC_A, 1);	
    HRPWM_enableADCTrigger(base, EPWM_SOC_B);	
    HRPWM_setADCTriggerSource(base, EPWM_SOC_B, EPWM_SOC_TBCTR_ZERO);	
    HRPWM_setADCTriggerEventPrescale(base, EPWM_SOC_B, 1);	
    HRPWM_enableAutoConversion(base);	
}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init(){
	debug_pin_init();
	transient_det_pin_init();
}

void debug_pin_init(){
	GPIO_writePin(debug_pin, 0);
	GPIO_setPadConfig(debug_pin, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(debug_pin, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(debug_pin, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(debug_pin, GPIO_CORE_CPU1);
}
void transient_det_pin_init(){
	GPIO_writePin(transient_det_pin, 0);
	GPIO_setPadConfig(transient_det_pin, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(transient_det_pin, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(transient_det_pin, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(transient_det_pin, GPIO_CORE_CPU1);
}

//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
void INPUTXBAR_init(){
	myINPUTXBARINPUT0_init();
	myINPUTXBARINPUT1_init();
	myINPUTXBARINPUT2_init();
}

void myINPUTXBARINPUT0_init(){
	XBAR_setInputPin(myINPUTXBARINPUT0_INPUT, myINPUTXBARINPUT0_SOURCE);
}
void myINPUTXBARINPUT1_init(){
	XBAR_setInputPin(myINPUTXBARINPUT1_INPUT, myINPUTXBARINPUT1_SOURCE);
}
void myINPUTXBARINPUT2_init(){
	XBAR_setInputPin(myINPUTXBARINPUT2_INPUT, myINPUTXBARINPUT2_SOURCE);
}

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
void INTERRUPT_init(){
	
	// Interrupt Setings for INT_myCLA01
	Interrupt_register(INT_myCLA01, &cla1Isr1);
	Interrupt_enable(INT_myCLA01);
	
	// Interrupt Setings for INT_ControlPWM
	Interrupt_register(INT_ControlPWM, &INT_ControlPWM_ISR);
	Interrupt_enable(INT_ControlPWM);
	
	// Interrupt Setings for INT_transient_det_pin_XINT
	Interrupt_register(INT_transient_det_pin_XINT, &INT_transient_det_pin_XINT_ISR);
	Interrupt_enable(INT_transient_det_pin_XINT);
}
//*****************************************************************************
//
// MEMCFG Configurations
//
//*****************************************************************************
void MEMCFG_init(){
	//
	// Initialize RAMs
	//
	//
	// Configure LSRAMs
	//
	MemCfg_setLSRAMControllerSel(MEMCFG_SECT_LS0, MEMCFG_LSRAMCONTROLLER_CPU_CLA1);
	MemCfg_setCLAMemType(MEMCFG_SECT_LS0, MEMCFG_CLA_MEM_PROGRAM);
	MemCfg_setLSRAMControllerSel(MEMCFG_SECT_LS1, MEMCFG_LSRAMCONTROLLER_CPU_ONLY);
	MemCfg_setLSRAMControllerSel(MEMCFG_SECT_LS2, MEMCFG_LSRAMCONTROLLER_CPU_CLA1);
	MemCfg_setCLAMemType(MEMCFG_SECT_LS2, MEMCFG_CLA_MEM_DATA);
	MemCfg_setLSRAMControllerSel(MEMCFG_SECT_LS3, MEMCFG_LSRAMCONTROLLER_CPU_CLA1);
	MemCfg_setCLAMemType(MEMCFG_SECT_LS3, MEMCFG_CLA_MEM_DATA);
	MemCfg_setLSRAMControllerSel(MEMCFG_SECT_LS4, MEMCFG_LSRAMCONTROLLER_CPU_ONLY);
	MemCfg_setLSRAMControllerSel(MEMCFG_SECT_LS5, MEMCFG_LSRAMCONTROLLER_CPU_ONLY);
	MemCfg_setLSRAMControllerSel(MEMCFG_SECT_LS6, MEMCFG_LSRAMCONTROLLER_CPU_ONLY);
	MemCfg_setLSRAMControllerSel(MEMCFG_SECT_LS7, MEMCFG_LSRAMCONTROLLER_CPU_ONLY);
	//
	// Configure GSRAMs
	//
	//
	// Configure Access Protection for RAMs
	//
	MemCfg_setProtection(MEMCFG_SECT_LS0, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE);
	MemCfg_setProtection(MEMCFG_SECT_LS1, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE);
	MemCfg_setProtection(MEMCFG_SECT_LS2, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE);
	MemCfg_setProtection(MEMCFG_SECT_LS3, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE);
	MemCfg_setProtection(MEMCFG_SECT_LS4, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE);
	MemCfg_setProtection(MEMCFG_SECT_LS5, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE);
	MemCfg_setProtection(MEMCFG_SECT_LS6, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE);
	MemCfg_setProtection(MEMCFG_SECT_LS7, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS0, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS1, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS2, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS3, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	//
	// Lock/Commit Registers
	//
	//
	// Enable Access Violation Interrupt
	//
	//
	// Correctable error Interrupt
	//
	MemCfg_setCorrErrorThreshold(0);
	MemCfg_disableCorrErrorInterrupt(MEMCFG_CERR_CPUREAD);
}        
//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************
void SYNC_init(){
	SysCtl_setSyncOutputConfig(SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT);
	//
	// For EPWM1, the sync input is: SYSCTL_SYNC_IN_SRC_EXTSYNCIN1
	//
	SysCtl_setSyncInputConfig(SYSCTL_SYNC_IN_EPWM4, SYSCTL_SYNC_IN_SRC_EPWM1SYNCOUT);
	SysCtl_setSyncInputConfig(SYSCTL_SYNC_IN_EPWM7, SYSCTL_SYNC_IN_SRC_EPWM1SYNCOUT);
	SysCtl_setSyncInputConfig(SYSCTL_SYNC_IN_ECAP1, SYSCTL_SYNC_IN_SRC_EPWM1SYNCOUT);
	SysCtl_setSyncInputConfig(SYSCTL_SYNC_IN_ECAP4, SYSCTL_SYNC_IN_SRC_EPWM1SYNCOUT);
	SysCtl_setSyncInputConfig(SYSCTL_SYNC_IN_ECAP6, SYSCTL_SYNC_IN_SRC_EPWM1SYNCOUT);
	//
	// SOCA
	//
	SysCtl_enableExtADCSOCSource(0);
	//
	// SOCB
	//
	SysCtl_enableExtADCSOCSource(0);
}
//*****************************************************************************
//
// XINT Configurations
//
//*****************************************************************************
void XINT_init(){
	transient_det_pin_XINT_init();
}

void transient_det_pin_XINT_init(){
	GPIO_setInterruptType(transient_det_pin_XINT, GPIO_INT_TYPE_RISING_EDGE);
	GPIO_setInterruptPin(transient_det_pin, transient_det_pin_XINT);
	GPIO_enableInterrupt(transient_det_pin_XINT);
}

