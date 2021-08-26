#include <Arduino.h>
//#include "TFT_eSPI.h"
//#include "Application.h"

//Application *application;

void setup()
{
  //Serial.begin(115200);
  pinMode(13, OUTPUT);

  // pinMode(WIO_MIC, INPUT);
  // TFT_eSPI *display = new TFT_eSPI();
  // display->begin();
  // display->setRotation(1);

  // application = new Application(*display);
  // application->begin();
}

bool isLEDOn = false;

void loop()
{
  //Serial.println("loop");
  delay(1000);
  digitalWrite(13, isLEDOn);
  isLEDOn = !isLEDOn;
  // application->loop();
}