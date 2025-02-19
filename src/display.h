#ifndef DISPLAY_H
#define DISPLAY_H

#include "ssd1306.h"
#include <stdio.h>

#define WIDTH 128
#define HEIGHT 64

extern volatile uint y_borda;
extern volatile uint x_borda;

void handle_display_rect(ssd1306_t *ssd, uint16_t vrx_value, uint16_t vry_value);
void blit(ssd1306_t *ssd, bool borda);

#endif // DISPLAY_H
