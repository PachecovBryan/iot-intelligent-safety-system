#include <Arduino.h>
#include "alarm.h"

Alarm::Alarm(int buzzerPin, int ledPin) {
    this->buzzerPin = buzzerPin;
    this->ledPin = ledPin;

    pinMode(buzzerPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
}

void Alarm::activate() {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
}

void Alarm::deactivate() {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
}