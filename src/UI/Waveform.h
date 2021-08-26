#pragma once

#include "Component.h"

class Waveform : public Component
{
private:
  int *m_samples;
  int m_num_samples;

public:
  Waveform(TFT_eSPI &display, int x, int y, int width, int height, int num_samples);
  void update(int *samples);
  void _draw(TFT_eSPI &display);
};
