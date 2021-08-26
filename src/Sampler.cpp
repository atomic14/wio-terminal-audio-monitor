#include <Arduino.h>
#include "SAMD51_InterruptTimer.h"
#include "Sampler.h"

static Sampler *instance = NULL;

void timerIsr()
{
  instance->buffer[instance->current_index] = analogRead(WIO_MIC);
  instance->current_index++;
  // have we collected enough samples?
  if (instance->current_index >= instance->buffer_size)
  {
    // if we have then stop collecting
    instance->current_index = 0;
    instance->is_full = true;
    TC.stopTimer();
  }
}

Sampler::Sampler(int buffer_size)
{
  this->buffer_size = buffer_size;
  this->buffer = reinterpret_cast<int16_t *>(malloc(buffer_size * sizeof(int16_t)));
  this->current_index = 0;
  pinMode(WIO_MIC, INPUT);
  instance = this;
}

void Sampler::start()
{
  is_full = false;
  TC.startTimer(125, timerIsr); // approx 8KHz sample rate
}
