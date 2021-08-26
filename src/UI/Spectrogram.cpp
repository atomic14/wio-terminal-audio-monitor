#include <Arduino.h>
#include <TFT_eSPI.h>
#include "Spectrogram.h"
#include "Bitmap.h"
#include "Palette.h"

Spectrogram::Spectrogram(Palette *palette, int x, int y, int width, int height) : Component(x, y, width, height)
{
  m_palette = palette;
  this->bitmap = new Bitmap(width, height);
}

void Spectrogram::update(float *mag)
{
  bitmap->scroll_left();
  for (int i = 0; i < bitmap->height; i++)
  {
    bitmap->rows[bitmap->height - i - 1][bitmap->width - 1] = m_palette->get_color(mag[i]);
  }
}

void Spectrogram::_draw(TFT_eSPI &display)
{
  display.setSwapBytes(true);
  display.pushImage(x, y, bitmap->width, bitmap->height, bitmap->pixels);
  display.setSwapBytes(false);
}