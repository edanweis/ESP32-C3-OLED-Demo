#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <U8g2lib.h>

// OLED display configuration
#define SCREEN_WIDTH 128    // Declare as 128x64 even though actual is 72x40
#define SCREEN_HEIGHT 64    // This works better with offset
#define SCREEN_ADDRESS 0x3C // I2C address

// Display offset for 72x40 screen declared as 128x64
#define SCREEN_OFFSET_X 28 // X offset for SSD1306
#define SCREEN_OFFSET_Y 24 // Y offset for SSD1306

// Actual usable screen dimensions
#define ACTUAL_WIDTH 72
#define ACTUAL_HEIGHT 40

// ESP32-C3 pins
#define SDA_PIN 5  // I2C Data
#define SCL_PIN 6  // I2C Clock
#define LED_PIN 8  // Onboard LED (active LOW)
#define BOOT_PIN 9 // Boot button

// QR Code configuration
#define QR_CODE_URL "https://github.com/Pharkie/ESP32-C3-OLED-Demo"

// External display object reference (U8g2, HW I2C, no reset pin)
extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C display;

#endif // CONFIG_H