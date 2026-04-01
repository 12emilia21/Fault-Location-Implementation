/*
 * control_functions.h
 *
 *  Created on: Feb 15, 2023
 *      Author: Nacho
 */

#ifndef CONTROL_FUNCTIONS_H_
#define CONTROL_FUNCTIONS_H_

#include "driverlib.h"
#include "board.h"

#define PWM_TICKS_PERIOD     ((uint16_t) 5000)
#define PWM2_TICKS_PERIOD    ((uint16_t) 2500)

typedef struct {
  float32_t kp;
  float32_t ki;
  float32_t integrator ;
  float32_t output;
} PI_Controller;

#endif /* CONTROL_FUNCTIONS_H_ */


void set_duty_cycle(float32_t duty);
void init_PI( PI_Controller* controller, float32_t kp,float32_t ki);
void reset_PI(PI_Controller* controller);
void update_PI(float32_t error, PI_Controller* controller);
float32_t duty_cycle_saturation(float32_t duty);
