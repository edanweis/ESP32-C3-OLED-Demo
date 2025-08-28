#include "display_tests.h"

// Animated bar graph
void displayBarGraph()
{
    display.clearBuffer();

    display.setFont(u8g2_font_6x10_tr);
    display.setDrawColor(1);

    // Centered label
    const char* label = "Bar Graph";
    int16_t labelW = strlen(label) * 6;
    setCursorActual((ACTUAL_WIDTH - labelW) / 2, 0);
    display.print(label);

    // Dynamic bar count and sizing
    int numBars = (ACTUAL_WIDTH >= 60) ? 6 : 4;
    int barWidth = ACTUAL_WIDTH / (numBars * 2);
    int barSpacing = (ACTUAL_WIDTH - numBars * barWidth) / (numBars + 1);
    int barHeightMax = ACTUAL_HEIGHT - 12;
    for (int i = 0; i < numBars; i++)
    {
        int barHeight = (sin((millis() / 200.0) + i) + 1) * (barHeightMax / 2);
        int barX = barSpacing + i * (barWidth + barSpacing);
        fillRectActual(barX, ACTUAL_HEIGHT - barHeight, barWidth, barHeight, 1);

        // Value label centered on bar
        char buf[5];
        snprintf(buf, sizeof(buf), "%d", barHeight);
        int16_t valW = strlen(buf) * 6;
        setCursorActual(barX + (barWidth - valW) / 2, ACTUAL_HEIGHT - barHeight - 8);
        display.print(buf);
    }

    display.sendBuffer();
}