#include "temp_sensor.h"

TempSensor::TempSensor(DHT& dhtRef, float threshold)
    : dht(dhtRef) {
    this->threshold = threshold;
}

void TempSensor::begin() {
    dht.begin();
}

float TempSensor::read() {
    return dht.readTemperature();
}

bool TempSensor::isHigh() {
    float temp = read();
    return !isnan(temp) && temp > threshold;
}