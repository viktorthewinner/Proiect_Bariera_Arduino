#include "Button.hpp"
#include <Arduino.h> // Biblioteca pentru funcții precum millis()

Button::Button(int pin) {
  buttonPin = pin;
  lastButtonPressTime = 0;
  pinMode(buttonPin, INPUT_PULLUP);  
}

// Getter 
int Button::getButtonPin() const {
  return buttonPin;
}

// Setter
void Button::setButtonPin(int pin) {
  buttonPin = pin;
}

// Getter pentru timp
unsigned long Button::getLastButtonPressTime() const {
  return lastButtonPressTime;
}

// Setter pentru timp
void Button::setLastButtonPressTime(unsigned long time) {
  lastButtonPressTime = time;
}

void Button::update() {
  unsigned long currentTime = millis();  
  bool buttonState = digitalRead(buttonPin) == LOW; 

  if (buttonState && (currentTime - lastButtonPressTime) < 1000) {
    //(mai puțin de 1000ms de la ultima apăsare)
    lastButtonPressTime = currentTime; 
  }
}

bool Button::isPressedRapidly() {
  unsigned long currentTime = millis();
  return (currentTime - lastButtonPressTime) < 1000;  
}
