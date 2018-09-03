#ifndef FAN_H
#define FAN_H

#include <Arduino.h>


class Fan {

private:
    int pin;
    int pulseDuration;
    int restDuration;

    static const String LIGHT_POWER;
    static const String FAN_POWER;
    static const String FAN_LOW;
    static const String FAN_MEDIUM;
    static const String FAN_HIGH;

    static const char SHORT_PULSE;
    static const char LONG_PULSE;

    void doTransimission(const String &command);

public:
    Fan(int pin);
    Fan(int pin, int pulseDuration, int restDuration);

    void toggleLight();
    void fanOff();
    void fanLow();
    void fanMedium();
    void fanHigh();

};


#endif // FAN_H
