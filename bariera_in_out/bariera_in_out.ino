#include "LCDManager.hpp"
#include <Servo.h> // Biblioteca pentru controlul servomotoarelor
#include "Motor.hpp"

//  mesaje
const char* mesaje[] = {
  "Bun venit!",
  "Skoda Fabia",
  "Peugeot 1007",
  "Kia Sportage",
  "La revedere!"
};

const int numarMesaje = sizeof(mesaje) / sizeof(mesaje[0]);

// Definire pin buton
const int buttonPin = 7;

const int greenLed = 8;
const int redLed = 10;

Leds leds(8,10);

// Configurare pin pentru servomotor
const int motorPin = 9; //  servomotor
Motor motor(motorPin,leds);            //  Servo

// Creare obiect LCDManager
LCDManager lcdManager(12, 11, 5, 4, 3, 2, mesaje, numarMesaje, 2000, buttonPin,motor);



void setup() {
  // Inițializare LCD (16x2)
  leds.begin();
  lcdManager.begin(16, 2);
  
  motor.begin();

  motor.setPosition(0); // Poziția 0 grade
}

void loop() {
  lcdManager.update();

 
}
