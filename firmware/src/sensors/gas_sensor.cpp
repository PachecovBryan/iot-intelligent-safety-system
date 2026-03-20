#include <Arduino.h>
#include "gas_sensor.h"

GasSensor::GasSensor(int pin, int threshold) {
    this->pin = pin;
    this->threshold = threshold;
}

int GasSensor::read() {
    return analogRead(pin);
}

bool GasSensor::isDangerous() {
    return read() > threshold;
}