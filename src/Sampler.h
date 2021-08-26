#pragma once

class Sampler
{
private:
  int buffer_size;
  int16_t *buffer;
  int current_index;

public:
  bool is_full = false;
  Sampler(int buffer_size);
  void start();
  int16_t *get_buffer()
  {
    return buffer;
  }
  friend void timerIsr();
};