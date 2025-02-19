#include "pwm.h"

uint pwm_setup(uint LED) {
    gpio_set_function(LED, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(LED);
    pwm_set_wrap(slice, 4090);
    pwm_set_clkdiv(slice, 69); // 442Hz
    pwm_set_enabled(slice, true);
    return slice;
}
