#include <Arduino.h>
#include <LovyanGFX.hpp>
#include "UI.h"
#include "UI/Waveform.h"
#include "UI/Palette.h"
#include "UI/GraphicEqualiser.h"
#include "UI/Spectrogram.h"

UI::UI(LGFX &display, int window_size) : m_display(display)
{
  Serial.printf("Display is %d x %d\n", display.width(), display.height());
  m_palette = new Palette();
  m_waveform = new Waveform(display, 0, 0, display.width(), display.height(), window_size);
  m_graphic_equaliser = new GraphicEqualiser(m_palette, 0, 0, display.width(), display.height(), window_size);
  m_spectrogram = new Spectrogram(m_palette, 0, 0, display.width(), display.height());
  // start off with the spectrogram hidden
  m_waveform->visible = false;
  m_spectrogram->visible = true;
  m_graphic_equaliser->visible = false;
  // create a drawing task to update our UI
  // xTaskCreatePinnedToCore(drawing_task, "Drawing Task", 4096, this, 1, &m_draw_task_handle, 1);
}

void UI::toggle_display()
{
  bool tmp = m_graphic_equaliser->visible;
  m_graphic_equaliser->visible = m_spectrogram->visible;
  m_spectrogram->visible = m_waveform->visible;
  m_waveform->visible = tmp;
}

void UI::update(int *samples, int *fft)
{
  m_waveform->update(samples);
  m_graphic_equaliser->update(fft);
  m_spectrogram->update(fft);
  draw();
}

unsigned long draw_time = 0;
int draw_count = 0;
void UI::draw()
{
  auto start = millis();
  m_spectrogram->draw(m_display);
  m_graphic_equaliser->draw(m_display);
  m_waveform->draw(m_display);
  auto end = millis();
  draw_time += end - start;
  draw_count++;
  if (draw_count == 20)
  {
    Serial.printf("Drawing time %ld\n", draw_time / 20);
    draw_count = 0;
    draw_time = 0;
  }
}