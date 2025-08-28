#include "display_tests.h"

// Moving line patterns
void displayLinePattern()
{
    display.clearBuffer();

    display.setFont(u8g2_font_6x10_tr);
    display.setDrawColor(1);

    // Centered label
    const char* label = "Lines";
    int16_t labelW = strlen(label) * 6;
    setCursorActual((ACTUAL_WIDTH - labelW) / 2, 0);
    display.print(label);

    // Animated diagonal lines, dynamic spacing
    int offset = (millis() / 50) % (ACTUAL_WIDTH / 6);
    int diagStep = ACTUAL_WIDTH / 8;
    int diagLen = ACTUAL_WIDTH / 4;
    int y1 = ACTUAL_HEIGHT / 4;
    int y2 = (ACTUAL_HEIGHT * 3) / 4;
    for (int i = -diagLen; i < ACTUAL_WIDTH + diagLen; i += diagStep)
    {
        int x2 = i + offset + diagLen;
        drawLineActual(i + offset, y1, x2, y2, 1);
    }

    // Vertical lines moving horizontally, dynamic spacing
    int vOffset = (millis() / 100) % ACTUAL_WIDTH;
    int vStep = ACTUAL_WIDTH / 3;
    for (int i = 0; i < 3; i++)
    {
        int x = (vOffset + i * vStep) % ACTUAL_WIDTH;
        drawLineActual(x, ACTUAL_HEIGHT / 4, x, ACTUAL_HEIGHT - 1, 1);
    }

    display.sendBuffer();
}