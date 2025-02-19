#include "joystick.h"
#include "gpio.h"

uint16_t adc_read_input(uint input) {
    adc_select_input(input);
    return adc_read();
}

void handle_leds_joystick_pwm(uint16_t vrx_value, uint16_t vry_value) {
    if (vry_value < 2087 + 600 && vry_value > 2087 - 600)
        blue_on = false;
    else
        blue_on = true;

    if (vrx_value < 1880 + 600 && vrx_value > 1880 - 600)
        red_on = false;
    else
        red_on = true;

    if (blue_on)
        pwm_set_gpio_level(LED_BLUE, vry_value);
    else
        pwm_set_gpio_level(LED_BLUE, 0);

    if (red_on)
        pwm_set_gpio_level(LED_RED, vrx_value);
    else
        pwm_set_gpio_level(LED_RED, 0);
}
