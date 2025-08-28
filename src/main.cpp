/*
 * ESP32-C3 OLED Hello World Demo (U8g2 SSD1306)
 *
 * This sketch displays "Hello World" and test patterns on a 0.42 inch OLED display
 * connected to an ESP32-C3 development board using the U8g2 library.
 *
 * Hardware:
 * - ESP32-C3 Development Board with onboard 0.42" OLED (72x40 pixels, SSD1306)
 * - Pinout: SCL=GPIO6, SDA=GPIO5, LED=GPIO8 (active LOW), Boot Button=GPIO9
 * - Display declared as 128x64 with offset (X=30, Y=12) for visible window
 */

#include "config.h"
#include "display_tests.h"

// Create display object for SSD1306 (U8g2, HW I2C, no reset pin)
U8G2_SSD1306_128X64_NONAME_F_HW_I2C display(U8G2_R0, /* reset=*/U8X8_PIN_NONE, /* clock=*/SCL_PIN, /* data=*/SDA_PIN);

void setup()
{
    // Initialize serial communication for debugging
    Serial.begin(115200);
    while (!Serial) { delay(10); }

    Serial.println("ESP32-C3 OLED Hello World Demo (U8g2 SSD1306)");

    // Initialize LED pin (active LOW)
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH); // LED off

    // Initialize display
    display.begin();
    display.clearBuffer();
    display.setFont(u8g2_font_ncenB08_tr); // Set a default font
    display.setContrast(255);

    Serial.println("SSD1306 OLED initialized successfully!");

    // Show initial display buffer contents on the screen
    display.sendBuffer();
    delay(1000);

    // Display pixel test
    displayPixelTest();
}

void loop()
{
    // Cycle through different test patterns
    static uint8_t testMode = 0;
    static unsigned long lastChange = 0;

    // QR code gets longer display time (4s) vs other tests (2s)
    unsigned long displayTime = (testMode == 8) ? 4000 : 2000;

    if (millis() - lastChange > displayTime)
    {
        lastChange = millis();
        testMode = (testMode + 1) % 9; // 9 different tests
    }

    switch (testMode)
    {
    case 0:
        displayPixelTest();
        break;
    case 1:
        displayBorderTest();
        break;
    case 2:
        displayPatternTest();
        break;
    case 3:
        displayScrollText();
        break;
    case 4:
        displayBarGraph();
        break;
    case 5:
        displayCircleTest();
        break;
    case 6:
        displayLinePattern();
        break;
    case 7:
        displayGradientTest();
        break;
    case 8:
        displayQRCode();
        break;
    }

    delay(50);
}