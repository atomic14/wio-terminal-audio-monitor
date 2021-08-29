#include <Arduino.h>
#include "Application.h"
#include <TFT_eSPI.h>
#include <LovyanGFX.hpp>
#include "Display.h"

Application *application;

#define USE_LGFX
// #define USE_TFT

void setup()
{
  Serial.begin(115200);

  Serial.println("Starting");

#ifdef USE_LGFX
  LGFX *lcd = new LGFX();
  lcd->begin();
  lcd->setColorDepth(16);
  lcd->setBrightness(50);
  lcd->setRotation(1);
  Display *display = new DisplayWrapper<LGFX>(*lcd);
#endif
#ifdef USE_TFT
  TFT_eSPI *lcd = new TFT_eSPI();
  lcd->begin();
  lcd->setRotation(3);
  Display *display = new DisplayWrapper<TFT_eSPI>(*lcd);
#endif
  application = new Application(*display);
  application->begin();
}

void loop()
{
  application->loop();
}