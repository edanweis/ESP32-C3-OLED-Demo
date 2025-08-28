#include "display_tests.h"

// Scrolling text test
void displayScrollText()
{
    static int16_t textX = ACTUAL_WIDTH;
    static unsigned long lastScroll = 0;

    if (millis() - lastScroll > 67)
    {
        lastScroll = millis();
        textX -= 2;
        if (textX < -60)
            textX = ACTUAL_WIDTH;
    }

    display.clearBuffer();

    display.setFont(u8g2_font_6x10_tr);
    display.setDrawColor(1);
    setCursorActual(textX, 15);
    display.print(F("Scrolling Text!"));

    // Add a static header
    setCursorActual(0, 0);
    display.print(F("Scroll Test"));

    // Add moving indicator
    drawPixelActual((millis() / 100) % ACTUAL_WIDTH, 35, 1);

    display.sendBuffer();
}