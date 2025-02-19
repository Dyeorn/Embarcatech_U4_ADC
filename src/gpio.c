#include "gpio.h"
#include "pico/bootrom.h"

volatile bool red_on = false;
volatile bool blue_on = false;
volatile bool leds_pwm = true;
volatile bool borda = false;
volatile uint y_borda = 3;
volatile uint x_borda = 3;

volatile uint32_t last_time;

void gpio_irq_handler(uint gpio, uint32_t event_mask) {
    uint32_t current_time = to_us_since_boot(get_absolute_time());
    if (current_time - last_time > 200000) {
        if (!gpio_get(BUTTON_BOOTSEL)) {
            last_time = current_time;
            reset_usb_boot(0, 0);
        }
        if (!gpio_get(BUTTON_JOYSTICK)) {
            gpio_put(LED_GREEN, !gpio_get(LED_GREEN));
            borda = !borda;
            x_borda++;
            y_borda++;
            last_time = current_time;
        }
        if (!gpio_get(BUTTON_A)) {
            leds_pwm = !leds_pwm;
            last_time = current_time;
        }
    }
}

void gpio_init_pins() {
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);

    gpio_init(BUTTON_JOYSTICK);
    gpio_set_dir(BUTTON_JOYSTICK, GPIO_IN);
    gpio_pull_up(BUTTON_JOYSTICK);

    gpio_init(BUTTON_BOOTSEL);
    gpio_set_dir(BUTTON_BOOTSEL, GPIO_IN);
    gpio_pull_up(BUTTON_BOOTSEL);

    gpio_set_irq_enabled_with_callback(BUTTON_BOOTSEL, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(BUTTON_JOYSTICK, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
}
