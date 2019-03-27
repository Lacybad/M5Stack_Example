/*
 Example sketch for the Playstation Buzz library - developed by Kristian Lauszus
 For more information visit my blog: http://blog.tkjelectronics.dk/ or
 send me an e-mail:  kristianl@tkjelectronics.com
 */

#include <PSBuzz.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
PSBuzz Buzz(&Usb);

void setup() {
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); // Halt
  }
  Serial.println(F("\r\nPS Buzz Library Started"));
}

void loop() {
  Usb.Task();

  if (Buzz.connected()) {
    for (uint8_t i = 0; i < 4; i++) {
      if (Buzz.getButtonClick(RED_, i)) {
        Buzz.setLedToggle(i); // Toggle the LED
        Serial.println(F("RED_"));
      }
      if (Buzz.getButtonClick(YELLOW_, i))
        Serial.println(F("YELLOW_"));
      if (Buzz.getButtonClick(GREEN_, i))
        Serial.println(F("GREEN_"));
      if (Buzz.getButtonClick(ORANGE_, i))
        Serial.println(F("ORANGE_"));
      if (Buzz.getButtonClick(BLUE_, i))
        Serial.println(F("BLUE_"));
    }
  }
}
