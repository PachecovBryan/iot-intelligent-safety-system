#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include <DHT.h>

class TempSensor {
  private:
    DHT& dht;
    float threshold;

  public:
    TempSensor(DHT& dhtRef, float threshold);

    void begin();
    float read();
    bool isHigh();
};

#endif