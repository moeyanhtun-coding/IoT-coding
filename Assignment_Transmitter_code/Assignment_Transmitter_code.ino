#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h>  // Not actually used but needed to compile
#endif

RH_ASK driver(2000, 4, 2, 5);  // ESP8266 or ESP32: do not use pin 11 or 2

void setup() {
#ifdef RH_HAVE_SERIAL
  Serial.begin(9600);  // Debugging only
#endif
  if (!driver.init())
#ifdef RH_HAVE_SERIAL
    Serial.println("init failed");
#else
    ;
#endif
}

void loop() {
  const char *msg = "Min Ka Lar bar";

  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(200);
}