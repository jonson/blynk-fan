#include "Fan.h"
#include "Arduino.h"

#define DEFAULT_PULSE_DURATION 445;
#define DEFAULT_REST_DURATION 14000;

const String Fan::LIGHT_POWER = "0100101010110101000101010";
const String Fan::FAN_POWER = "0100101010110101011101010";
const String Fan::FAN_LOW = "0100101010110101001111010";
const String Fan::FAN_MEDIUM = "0100101010110101010111010";
const String Fan::FAN_HIGH = "0100101010110101000111010";

const char Fan::SHORT_PULSE = '0';
const char Fan::LONG_PULSE = '1';

Fan::Fan(int pin) {
    this->pin = pin;
    this->pulseDuration = DEFAULT_PULSE_DURATION;
    this->restDuration = DEFAULT_REST_DURATION;
    pinMode(this->pin, OUTPUT);
    digitalWrite(this->pin, 0);
}

Fan::Fan(int pin, int pulseDuration, int restDuration) {
    this->pin = pin;
    this->pulseDuration = pulseDuration;
    this->restDuration = restDuration;
    pinMode(this->pin, OUTPUT);
    digitalWrite(this->pin, 0);
}

void Fan::toggleLight() {
    doTransimission(LIGHT_POWER);
}

void Fan::fanOff() {
    doTransimission(FAN_POWER);
}

void Fan::fanLow() {
    doTransimission(FAN_LOW);
}

void Fan::fanMedium() {
    doTransimission(FAN_MEDIUM);
}

void Fan::fanHigh() {
    doTransimission(FAN_HIGH);
}

void Fan::doTransimission(const String &command) {

    for (int attempt = 0; attempt < 24; attempt++) {
        for (uint i = 0; i < command.length(); i++) {
            char cmd = command.charAt(i);
            int signals[3] = {0, 0, 0};

            if (cmd == SHORT_PULSE) {
                signals[0] = 0;
                signals[1] = 0;
                signals[2] = 1;
            } else if (cmd == LONG_PULSE) {
                signals[0] = 0;
                signals[1] = 1;
                signals[2] = 1;
            }

            for (int signalIndex = 0; signalIndex < 3; signalIndex++) {
                digitalWrite(this->pin, signals[signalIndex]);
                delayMicroseconds(this->pulseDuration);
                digitalWrite(this->pin, 0);
            }
        }
        delayMicroseconds(this->restDuration);
    }
}