#ifndef LEDS_HPP
#define LEDS_HPP

#include <Arduino.h> 

class Leds
{
  int Green;
  int Red;

  public:

  Leds();
  Leds(int g,int r);

  int getGreen()const;
  int getRed()const;

  void begin();
  
};

#endif
