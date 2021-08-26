#include <Arduino.h>
#include "Application.h"
#include <TFT_eSPI.h>
#include <LovyanGFX.hpp>

Application *application;
LGFX *display = new LGFX();
void setup()
{
  Serial.begin(115200);

  Serial.println("Starting");

  // TFT_eSPI *display = new TFT_eSPI();
  display->begin();
  display->setRotation(1);
  display->setBrightness(255);
  display->setColorDepth(16);

  application = new Application(*display);
  application->begin();
}

void loop()
{
  application->loop();
}