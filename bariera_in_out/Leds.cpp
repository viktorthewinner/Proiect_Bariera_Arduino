#include "Leds.hpp"


Leds::Leds()
{
  
}

Leds::Leds(int g,int r)
{
  Green=g;
  Red=r;
}

void Leds::begin()
{
  pinMode(Green,OUTPUT);
  pinMode(Red,OUTPUT);

   digitalWrite(Green, HIGH);

}

int Leds::getGreen()const
{
  return Green;
}

int Leds::getRed()const
{
  return Red;
}
