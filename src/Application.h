#pragma once

class UI;
class Processor;
class Sampler;
class LGFX;

class Application
{
private:
  int m_window_size;
  int16_t *m_sample_buffer;
  UI *m_ui;
  Processor *m_processor;
  Sampler *m_sampler;

public:
  Application(LGFX &display);
  void begin();
  void loop();
};