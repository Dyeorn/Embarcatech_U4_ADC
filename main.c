#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "src/gpio.h"
#include "src/pwm.h"
#include "src/display.h"
#include "src/joystick.h"
#include "src/i2c.h"

#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define endereco 0x3C

ssd1306_t ssd;

int main() {
    stdio_init_all();
    adc_init();
    i2c_init(I2C_PORT, 400 * 1000);
    
    gpio_init_pins();
    i2c_init_pins(I2C_PORT, I2C_SDA, I2C_SCL);
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT);
    ssd1306_config(&ssd);
    ssd1306_send_data(&ssd);

    ssd1306_fill(&ssd, false);
    ssd1306_send_data(&ssd);

    uint slice_red = pwm_setup(LED_RED);
    uint slice_blue = pwm_setup(LED_BLUE);

    while (true) {
        blit(&ssd, borda);
        uint16_t vrx_value = adc_read_input(1);
        uint16_t vry_value = adc_read_input(0);
        
        if (leds_pwm) {
            handle_leds_joystick_pwm(vrx_value, vry_value);
        }
        handle_display_rect(&ssd, vrx_value, vry_value);
        sleep_ms(200);
    }
}
