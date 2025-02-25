#ifndef LCDMANAGER_HPP
#define LCDMANAGER_HPP

#include <LiquidCrystal.h>
#include "Button.hpp"
#include "Motor.hpp"
#include "Leds.hpp"


class LCDManager {
  private:
    LiquidCrystal lcd;           // Obiectul LCD
    const char** messages;       // Lista de mesaje
    int numMessages;             // Numărul total de mesaje
    int currentIndex;            // Indexul mesajului curent
    unsigned long previousTime;  // Timpul anterior pentru temporizare
    unsigned long interval;      // Intervalul de schimbare a mesajului
    Button buton;
    Motor motor;

    

  public:
    LCDManager(int rs, int en, int d4, int d5, int d6, int d7, const char** messages, int numMessages, unsigned long interval, Button buton,Motor motor);

    void begin(int columns, int rows);  // Inițializare LCD
    void update();                      // Actualizare LCD
};

#endif
