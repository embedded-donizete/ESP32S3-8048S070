#include <iostream>
#include <Arduino.h>
#include <SD.h>

void setup()
{
  delay(5000);

  Serial.begin(115200);
  while (!SD.begin())
  {
    log_d("Mount failed");
  }

  delay(5000);

  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
  Serial.printf("SD Card Size: %lluMB\n", cardSize);

  log_d("Total heap: %d", ESP.getHeapSize());
  log_d("Free heap: %d", ESP.getFreeHeap());
  log_d("Total PSRAM: %d", ESP.getPsramSize());
  log_d("Free PSRAM: %d", ESP.getFreePsram());

  fs::File file = SD.open("/doni.txt", FILE_WRITE);
  file.print("Hello World");
  file.close();
}

void loop()
{
  fs::File file = SD.open("/doni.txt");
  while (file.available())
  {
    Serial.print(file.read());
  }
  file.close();

  delay(10000);
}