#ifndef PWM_H
#define PWM_H

#include "hardware/pwm.h"
#include "pico/stdlib.h"

#define LED_RED 13
#define LED_BLUE 12

uint pwm_setup(uint LED);

#endif // PWM_H
