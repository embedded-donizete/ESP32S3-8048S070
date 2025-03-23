#include <Arduino.h>

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  log_d("Total heap: %d", ESP.getHeapSize());
  log_d("Free heap: %d", ESP.getFreeHeap());
  log_d("Total PSRAM: %d", ESP.getPsramSize());
  log_d("Free PSRAM: %d", ESP.getFreePsram());
  delay(1000);
}