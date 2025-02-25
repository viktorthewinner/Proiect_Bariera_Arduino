#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <Servo.h>
#include <Arduino.h> // Biblioteca pentru funcții precum millis()
#include "Leds.hpp"




class Motor {
  private:
    Servo motor;    // Obiectul Servo pentru controlul motorului
    int motorPin;
    unsigned long motorLastUpdate;
    Leds leds;


  public:
    Motor(int motorPin,Leds leds);

    void begin();

    void setPosition(int angle);

    int getMotorPin();

    void setMotorPin(int motorPin);

    unsigned long getMotorLastUpdate() const ;
    void setMotorLastUpdate(unsigned long time);

    Leds getLeds()const;
  
    void barrier();
};

#endif
