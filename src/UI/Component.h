#pragma once

class LGFX;
class Component
{
public:
  int x, y, width, height;
  bool visible;
  Component(int x, int y, int width, int height) : x(x), y(y), width(width), height(height), visible(true)
  {
  }
  virtual void _draw(LGFX &display) = 0;
  void draw(LGFX &display)
  {
    if (visible)
    {
      _draw(display);
    }
  }
};