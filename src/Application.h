#pragma once

class UI;
class Processor;
class Sampler;
class Display;

class Application
{
private:
  int m_window_size;
  UI *m_ui;
  Processor *m_processor;
  Sampler *m_sampler;

public:
  Application(Display &display);
  void begin();
  void loop();
};