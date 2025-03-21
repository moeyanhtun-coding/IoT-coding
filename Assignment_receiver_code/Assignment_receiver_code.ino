
#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h>  // Not actually used but needed to compile
#endif

RH_ASK driver(2000, 2, 4, 5);  // ESP8266 or ESP32: do not use pin 11 or 2

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
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen))  // Non-blocking
  {
    //int i;

    // Message with a good checksum received, dump it.
    driver.printBuffer("Got:", buf, buflen);
String rcv;
    for(int i = 0; i < buflen; i++){
      rcv += (char)buf[i];
    }
    Serial.println(rcv);
  }
  
  delay(200);
}
