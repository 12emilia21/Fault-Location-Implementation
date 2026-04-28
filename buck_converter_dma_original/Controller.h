/*
 * Controller.h
 *
 *  Created on: Mar 10, 2023
 *      Author: Nacho
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"
#include "control_functions.h"
#include "transient_det.h"
#include "defines.h"

// Sample controller data
uint16_t ADCC_results[6];
uint16_t ADCA_results[2];
uint16_t ADCB_results[2];
#pragma DATA_SECTION(ADCC_results,    "ramgs0");
#pragma DATA_SECTION(ADCA_results,    "ramgs0");
#pragma DATA_SECTION(ADCB_results,    "ramgs0");

const void * ADCC0_results_add = (const void *) ADCC_results;
const void * ADCC0_Result_base = (const void *) myADC1_RESULT_BASE;
const void * ADCA0_results_add = (const void *) ADCA_results;
const void * ADCA0_Result_base = (const void *) myADC0_RESULT_BASE;
const void * ADCB0_results_add = (const void *) ADCB_results;
const void * ADCB0_Result_base = (const void *) myADC2_RESULT_BASE;

float32_t d                = 0;
float32_t fixed_d          = 0.5;
bool      fixed_duty_cycle = 1;
float32_t Iin_avg          = 0;
float32_t Io_avg           = 0;
float32_t Il_avg           = 0;
float32_t Vo_avg           = 0;
float32_t Vin_avg          = 0;
float32_t Vo_error         = 0;
float32_t Il_error         = 0;
float32_t Vo_ref           = 10;

PI_Controller Vo_controller;
PI_Controller Il_controller;

#define ADC_CODES           ((uint16_t)(4096))

// Regular operation
//#define IIN_MAX ((float32_t)6.75)
//#define IIN_SCALE IIN_MAX/ADC_CODES
//#define IIN_OFST 0
//
//#define IOUT_MAX ((float32_t)6.75)
//#define IOUT_SCALE IOUT_MAX/ADC_CODES
//#define IOUT_OFST 0
//
//#define IL_MAX ((float32_t)6.75)        // 50% above rated (9A) - 6.75
//#define IL_SCALE IL_MAX/ADC_CODES
//#define IL_OFST 0
//
//#define VIN_MAX ((float32_t)33)         // 10% above rated (60V) - 33
//#define VIN_SCALE VIN_MAX/ADC_CODES
//#define VIN_OFST 0
//
//#define VOUT_MAX ((float32_t)33)        
//#define VOUT_SCALE VOUT_MAX/ADC_CODES
//#define VOUT_OFST 0

// Fit to measure complete transient
#define IIN_MAX ((float32_t)35)
#define IIN_SCALE IIN_MAX/ADC_CODES
#define IIN_OFST 7

#define IOUT_MAX ((float32_t)35)
#define IOUT_SCALE IOUT_MAX/ADC_CODES
#define IOUT_OFST 7

#define IL_MAX ((float32_t)35)        // 50% above rated (9A) - 6.75
#define IL_SCALE IL_MAX/ADC_CODES
#define IL_OFST 7

#define VIN_MAX ((float32_t)60)         // 10% above rated (60V) - 33
#define VIN_SCALE VIN_MAX/ADC_CODES
#define VIN_OFST 0

#define VOUT_MAX ((float32_t)80)        
#define VOUT_SCALE VOUT_MAX/ADC_CODES
#define VOUT_OFST 26

#define num_samples  ((uint16_t)2)

#endif /* CONTROLLER_H_ */


void average_samples(void);
void duty_cycle_calculation(void);
void initializeDMA(void);
void configureDMAChannels(void);
void samples_to_cla(void);



