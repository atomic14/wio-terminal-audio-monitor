#pragma once

class Palette;
class Waveform;
class GraphicEqualiser;
class Spectrogram;
class LGFX;

class UI
{
private:
  Palette *m_palette;
  Waveform *m_waveform;
  GraphicEqualiser *m_graphic_equaliser;
  Spectrogram *m_spectrogram;
  LGFX &m_display;

public:
  UI(LGFX &display, int window_size);
  void toggle_display();
  void update(int *samples, int *fft);
  void draw();
};
