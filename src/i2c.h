#ifndef I2C_H
#define I2C_H

#include "hardware/i2c.h"

void i2c_init_pins(i2c_inst_t *i2c, uint sda, uint scl);

#endif // I2C_H
