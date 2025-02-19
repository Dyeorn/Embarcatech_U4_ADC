#include "i2c.h"
#include "hardware/gpio.h"

void i2c_init_pins(i2c_inst_t *i2c, uint sda, uint scl) {
    gpio_set_function(sda, GPIO_FUNC_I2C);
    gpio_set_function(scl, GPIO_FUNC_I2C);
    gpio_pull_up(sda);
    gpio_pull_up(scl);
}
