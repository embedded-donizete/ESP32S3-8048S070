#include <Arduino.h>
#include <SPI.h>

void setup()
{
  Serial.begin(115200);
  SPI.begin(SCK, MISO, MOSI, SS);
}

void loop()
{
  log_d("Total heap: %d", ESP.getHeapSize());
  log_d("Free heap: %d", ESP.getFreeHeap());
  log_d("Total PSRAM: %d", ESP.getPsramSize());
  log_d("Free PSRAM: %d", ESP.getFreePsram());
  delay(1000);
}