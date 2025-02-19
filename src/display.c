#include "display.h"

void handle_display_rect(ssd1306_t *ssd, uint16_t vrx_value, uint16_t vry_value) {
    // Inverter os valores do joystick
    int inverted_y = 4090 - vry_value;
    int y_pos = inverted_y / (4090 / 64);
    int x_pos = vrx_value / (4090 / 128);

    if (y_pos >= HEIGHT - (8 + y_borda)) // Impossibilita escapar da borda de baixo
        y_pos = HEIGHT - (8 + y_borda);

    if (y_pos <= y_borda) // Impossibilita escapar da borda de cima
        y_pos = y_borda;

    if (x_pos >= WIDTH - (8 + x_borda)) // Impossibilita escapar da borda da direita
        x_pos = WIDTH - (8 + x_borda);

    if (x_pos <= x_borda) // Impossibilita escapar da borda da esquerda
        x_pos = x_borda;

    ssd1306_rect(ssd, y_pos, x_pos, 8, 8, true, true); // Desenha um retângulo
    ssd1306_send_data(ssd);
    printf("x: %d, y: %d\n", x_pos, y_pos);
}

void blit(ssd1306_t *ssd, bool borda) {
    ssd1306_fill(ssd, false);
    if (borda) {
        ssd1306_rect(ssd, x_borda, y_borda, WIDTH - (2 * x_borda), HEIGHT - (2 * y_borda), borda, !borda); // Desenha um retângulo
    }
    ssd1306_send_data(ssd);
}
