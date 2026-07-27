/*
 * main.h
 *
 *  Created on: Mar 10, 2023
 *      Author: Nacho
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"
#include "control_functions.h"
#include "transient_det.h"
#include "defines.h"
//#include "moving_avg.h"

#endif /* MAIN_H_ */

void average_samples(void);
void duty_cycle_calculation(void);
void initializeDMA(void);
void configureDMAChannels(void);
void samples_to_cla(void);
void err_calc(void);

 
