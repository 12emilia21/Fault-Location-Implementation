/*
 * control_functios.c
 *
 *  Created on: Feb 15, 2023
 *      Author: Nacho
 */


#include "control_functions.h"


void set_duty_cycle(float32_t duty){
    EPWM_setCounterCompareValue(ControlPWM_BASE, EPWM_COUNTER_COMPARE_A,duty*PWM_TICKS_PERIOD);
    EPWM_setCounterCompareValue(ControlPWM_2fsw_BASE, EPWM_COUNTER_COMPARE_A,duty*PWM2_TICKS_PERIOD);
}

void init_PI( PI_Controller* controller, float32_t kp,float32_t ki){
    controller->kp = kp;
    controller->ki = ki;
    controller->integrator  = 0;
    controller->output = 0;
    return;
}
void reset_PI(PI_Controller* controller){
    controller->integrator  = 0;
    controller->output = 0;
    return;
}

void update_PI(float32_t error, PI_Controller* controller){
    controller->output = (controller->kp+controller->ki)*error + controller->ki*controller->integrator ;
    controller->integrator  = error+controller->integrator ;
    return;
}

float32_t duty_cycle_saturation(float32_t duty){
    static float32_t sat_duty = 0;
    if(duty>1){
        sat_duty = 1;
    }
    else if(duty<0){
        sat_duty = 0;
    }
    else{
        sat_duty = duty;
    }
    return sat_duty;
}
