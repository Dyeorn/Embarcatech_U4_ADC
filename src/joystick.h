#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include "pwm.h"

uint16_t adc_read_input(uint input);
void handle_leds_joystick_pwm(uint16_t vrx_value, uint16_t vry_value);

#endif // JOYSTICK_H
