#ifndef BUTTON_HPP
#define BUTTON_HPP

class Button
{
  private:
    int buttonPin;               
    unsigned long lastButtonPressTime;     
  public:
    Button(int pin);

    int getButtonPin() const;

    void setButtonPin(int pin);

    unsigned long getLastButtonPressTime() const;

    void setLastButtonPressTime(unsigned long time);

    void update();

    bool isPressedRapidly();
};

#endif
