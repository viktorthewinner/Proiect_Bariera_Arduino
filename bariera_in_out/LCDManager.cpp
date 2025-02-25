#include "LCDManager.hpp"
#include <Arduino.h> // Biblioteca pentru funcții precum millis()

LCDManager::LCDManager(int rs, int en, int d4, int d5, int d6, int d7, const char** messages, int numMessages, unsigned long interval, Button buton, Motor motor)
  : lcd(rs, en, d4, d5, d6, d7), messages(messages), numMessages(numMessages), interval(interval), currentIndex(0), previousTime(0), buton(buton), motor(motor) {}

void LCDManager::begin(int columns, int rows) {
  lcd.begin(columns, rows); // Inițializare dimensiuni LCD
}

void LCDManager::update() {
  unsigned long currentTime = millis();  // Obține timpul curent
  bool buttonState = digitalRead(buton.getButtonPin()) == LOW;

  // (apăsare la un interval mai mic decât intervalul specificat)
  if (buttonState && (currentTime - buton.getLastButtonPressTime()) < interval) {
    lcd.clear();
    lcd.setCursor(0, 0);

    Leds leds = motor.getLeds();

    lcd.print("Asteapta!");
    
    digitalWrite(leds.getGreen(), LOW);
    digitalWrite(leds.getRed(), HIGH);
    
    delay(1000);

    digitalWrite(leds.getGreen(),HIGH);
    digitalWrite(leds.getRed(),LOW);

    buton.setLastButtonPressTime(currentTime);
  }

  if (buttonState && (currentTime - previousTime >= interval)) {
    previousTime = currentTime;

    lcd.clear();
    lcd.setCursor(0, 0);
    delay(500);

    lcd.print(messages[currentIndex]);  // Afișează mesajul curent pe primul rând

    // Afișează mesajul pe al doilea rând
    lcd.setCursor(0, 1);
    if (currentIndex > 0 && currentIndex + 1 < numMessages) {
      lcd.print("Acces permis");

      motor.barrier();

    }

    currentIndex++;
    if (currentIndex >= numMessages) {
      currentIndex = 0;
    }

    buton.setLastButtonPressTime(currentTime);
  }
}
