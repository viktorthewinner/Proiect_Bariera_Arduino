#include "Motor.hpp"

Motor::Motor(int motorPin, Leds leds) : motorPin(motorPin), motorLastUpdate(0), leds(leds) {}

void Motor::begin() {
  motor.attach(motorPin);
}

void Motor::setPosition(int angle) {
  motor.write(angle);
}

int Motor::getMotorPin() {
  return motorPin;
}

void Motor::setMotorPin(int motorPin) {
  this->motorPin = motorPin;
  motor.attach(motorPin);
}


unsigned long Motor::getMotorLastUpdate() const {
  return motorLastUpdate;
}

void Motor::setMotorLastUpdate(unsigned long time) {
  motorLastUpdate = time;
}


Leds Motor::getLeds()const
{
  return leds;
}

void Motor::barrier()
{
  setPosition(7.5);
  unsigned long currentTime = millis();
  motorLastUpdate = currentTime;
  digitalWrite(leds.getGreen(), LOW);

  digitalWrite(leds.getRed(), HIGH);
  delay(250);

  setPosition(90);

  delay(250);


  setPosition(7.5);
  digitalWrite(leds.getRed(), LOW);
  digitalWrite(leds.getGreen(), HIGH);


}
