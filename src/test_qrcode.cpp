#include <qrcode.h>
#include "display_tests.h"

// QR Code for GitHub repository using QR library
void displayQRCode()
{
    display.clearBuffer();

    // QR Code version configuration
    const uint8_t QR_VERSION = 2;
    const uint8_t QR_ECC_LEVEL = 1; // ECC_MEDIUM

    // Create QR Code
    QRCode qrcode;
    uint8_t qrcodeData[qrcode_getBufferSize(QR_VERSION)];

    // Generate QR code for GitHub repository with medium error correction
    qrcode_initText(&qrcode, qrcodeData, QR_VERSION, QR_ECC_LEVEL, QR_CODE_URL);

    // Add quiet zone (4 modules minimum around QR code per QR standard)
    uint8_t quietZone = 4;
    uint8_t totalSize = qrcode.size + (2 * quietZone);

    // Calculate positioning for centered QR code with quiet zone
    uint8_t qrStartX = (ACTUAL_WIDTH - totalSize) / 2 + quietZone;
    uint8_t qrStartY = (ACTUAL_HEIGHT - totalSize) / 2 + quietZone;

    // Draw QR code modules as WHITE on BLACK background (no white background)
    for (uint8_t y = 0; y < qrcode.size; y++)
    {
        for (uint8_t x = 0; x < qrcode.size; x++)
        {
            if (qrcode_getModule(&qrcode, x, y))
            {
                drawPixelActual(qrStartX + x, qrStartY + y, 1);
            }
        }
    }

    // Add QR test label at top left (like other tests)
    display.setFont(u8g2_font_6x10_tr);
    display.setDrawColor(1);
    setCursorActual(0, 0);
    display.print(F("QR"));

    display.sendBuffer();
}