#include "display_tests.h"

// Circle and shape test
void displayCircleTest()
{
    display.clearBuffer();

    display.setFont(u8g2_font_6x10_tr);
    display.setDrawColor(1);

    // Centered label
    const char* label = "Shapes";
    int16_t labelW = strlen(label) * 6;
    setCursorActual((ACTUAL_WIDTH - labelW) / 2, 0);
    display.print(label);

    // Animated expanding circle, centered
    int minDim = (ACTUAL_WIDTH < ACTUAL_HEIGHT) ? ACTUAL_WIDTH : ACTUAL_HEIGHT;
    int maxRadius = minDim / 2 - 4;
    int radius = ((millis() / 100) % maxRadius) + 1;
    int centerX = ACTUAL_WIDTH / 2;
    int centerY = ACTUAL_HEIGHT / 2 + labelW / 12;

    for (int angle = 0; angle < 360; angle += 15)
    {
        int x = centerX + cos(angle * PI / 180) * radius;
        int y = centerY + sin(angle * PI / 180) * radius;
        if (x >= 0 && x < ACTUAL_WIDTH && y >= 0 && y < ACTUAL_HEIGHT)
        {
            drawPixelActual(x, y, 1);
        }
    }

    // Draw a triangle centered in the lower half
    int triY0 = ACTUAL_HEIGHT - 4;
    int triY1 = centerY + maxRadius / 2;
    int triX0 = centerX - maxRadius / 2;
    int triX1 = centerX + maxRadius / 2;
    drawLineActual(triX0, triY0, centerX, triY1, 1);
    drawLineActual(centerX, triY1, triX1, triY0, 1);
    drawLineActual(triX1, triY0, triX0, triY0, 1);

    display.sendBuffer();
}