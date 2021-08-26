#include <Arduino.h>
#include <TFT_eSPI.h>
#include "Application.h"
#include "UI/UI.h"
#include "AudioProcessing/Processor.h"
#include "config.h"
#include "Sampler.h"

// Task to process samples
void processing_task(void *param)
{
  Application *application = (Application *)param;
  // just sit in a loop processing samples as quickly as possible
  while (true)
  {
    application->process_samples();
  }
}

Application::Application(TFT_eSPI &display)
{
  m_window_size = WINDOW_SIZE;
  m_sample_buffer = (int16_t *)malloc(sizeof(int16_t) * WINDOW_SIZE);
  m_ui = new UI(display, m_window_size);
  m_processor = new Processor(m_window_size);
  m_sampler = new Sampler(m_window_size);
}

void Application::begin()
{
  // start sampling from the microphone
  m_sampler->start();
}

void Application::loop()
{
  // is the sampler full of data?
  if (m_sampler->is_full)
  {
    // run the fft
    m_processor->update(m_sampler->get_buffer());
    // update the UI
    m_ui->update(m_processor->m_fft_input, m_processor->m_energy);
    // start collecting samples again
    m_sampler->start();
  }
}