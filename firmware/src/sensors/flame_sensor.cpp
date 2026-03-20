#include <Arduino.h>
#include "flame_sensor.h"

FlameSensor::FlameSensor(int pin) {
    this->pin = pin;
}

void FlameSensor::begin() {
    pinMode(pin, INPUT_PULLUP);
}

bool FlameSensor::detected() {
    return digitalRead(pin) == LOW;
}