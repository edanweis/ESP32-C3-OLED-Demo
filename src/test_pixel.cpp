#include "display_tests.h"

// Test individual pixels and addressing
void displayPixelTest()
{
    display.clearBuffer();

    // Set font and color
    display.setFont(u8g2_font_6x10_tr);
    display.setDrawColor(1);
    setCursorActual(0, 0);

    // Display info about the screen
    display.print(F("72x40 Test"));
    setCursorActual(0, 10);
    display.print(F("Offset:"));
    display.print(SCREEN_OFFSET_X);
    display.print(F(","));
    display.print(SCREEN_OFFSET_Y);

    // Draw lines across the screen to test addressing
    drawLineActual(0, 20, ACTUAL_WIDTH - 1, 20, 1);  // Horizontal line
    drawLineActual(36, 0, 36, ACTUAL_HEIGHT - 1, 1); // Vertical line (center)

    // Test corner pixels
    drawPixelActual(0, 0, 1);
    drawPixelActual(ACTUAL_WIDTH - 1, 0, 1);
    drawPixelActual(0, ACTUAL_HEIGHT - 1, 1);
    drawPixelActual(ACTUAL_WIDTH - 1, ACTUAL_HEIGHT - 1, 1);

    // Show uptime
    setCursorActual(0, ACTUAL_HEIGHT - 8);
    display.print(F("Up:"));
    display.print(millis() / 1000);
    display.print(F("s"));

    display.sendBuffer();
}