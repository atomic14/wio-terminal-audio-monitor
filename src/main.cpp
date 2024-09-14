#include <Arduino.h>
#include "Application.h"
#ifdef USE_TFT
#include <TFT_eSPI.h>
#else
#include <LovyanGFX.hpp>
#include <LGFX_AUTODETECT.hpp>
#include <LGFX_TFT_eSPI.hpp>  
#endif
#include "Display.h"

Application *application;

#define USE_LGFX
//#define USE_TFT

void setup()
{
  Serial.begin(115200);

  Serial.println("Starting");

  TFT_eSPI *lcd = new TFT_eSPI();
  lcd->begin();
  #ifdef USE_TFT
  lcd->setRotation(3);
  #else
  lcd->setRotation(1);
  #endif
  Display *display = new DisplayWrapper<TFT_eSPI>(*lcd);
  application = new Application(*display);
  application->begin();
}

void loop()
{
  application->loop();
}
