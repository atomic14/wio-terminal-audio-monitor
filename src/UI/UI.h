#pragma once

class Palette;
class Waveform;
class GraphicEqualiser;
class Spectrogram;
class TFT_eSPI;

class UI
{
private:
  Palette *m_palette;
  Waveform *m_waveform;
  GraphicEqualiser *m_graphic_equaliser;
  Spectrogram *m_spectrogram;
  TFT_eSPI &m_display;

public:
  UI(TFT_eSPI &display, int window_size);
  void toggle_display();
  void update(int *samples, float *fft);
  void draw();
};
