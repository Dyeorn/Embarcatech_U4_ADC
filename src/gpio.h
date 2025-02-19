#ifndef GPIO_H
#define GPIO_H

#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "pico/bootrom.h"
#include "hardware/gpio.h"

#define LED_GREEN 11
#define BUTTON_JOYSTICK 22
#define BUTTON_A 5
#define BUTTON_BOOTSEL 6

extern volatile bool red_on;
extern volatile bool blue_on;
extern volatile bool leds_pwm;
extern volatile bool borda;
extern volatile uint y_borda;
extern volatile uint x_borda;

void gpio_irq_handler(uint gpio, uint32_t event_mask);
void gpio_init_pins();

#endif // GPIO_H
