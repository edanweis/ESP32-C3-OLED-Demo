#include "display_tests.h"

// Test pattern with alternating pixels
void displayPatternTest()
{
    display.clearBuffer();

    // Draw checkerboard pattern
    for (int16_t y = 0; y < ACTUAL_HEIGHT; y += 2)
    {
        for (int16_t x = 0; x < ACTUAL_WIDTH; x += 2)
        {
            drawPixelActual(x, y, 1);
            if (x + 1 < ACTUAL_WIDTH && y + 1 < ACTUAL_HEIGHT)
            {
                drawPixelActual(x + 1, y + 1, 1);
            }
        }
    }

    // Add text overlay (inverted: white box, black text)
    display.setFont(u8g2_font_6x10_tr);
    display.setDrawColor(1);
    display.drawBox(SCREEN_OFFSET_X + 2, SCREEN_OFFSET_Y + 2, 48, 12); // white box
    display.setDrawColor(0);
    setCursorActual(2, 2);
    display.print(F("Pattern"));
    display.setDrawColor(1); // restore

    display.sendBuffer();
}