#include "display_tests.h"

// Test all pixels by displaying a border around the entire 72x40 area
void displayBorderTest()
{
    display.clearBuffer();

    // Draw a single pixel at each exact corner of the visible area
    drawPixelActual(0, 0, 1);
    drawPixelActual(ACTUAL_WIDTH - 1, 0, 1);
    drawPixelActual(0, ACTUAL_HEIGHT - 1, 1);
    drawPixelActual(ACTUAL_WIDTH - 1, ACTUAL_HEIGHT - 1, 1);

    display.sendBuffer();
}