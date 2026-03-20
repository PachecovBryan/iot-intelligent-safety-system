#ifndef GAS_SENSOR_H
#define GAS_SENSOR_H

class GasSensor {
  private:
    int pin;
    int threshold;

  public:
    GasSensor(int pin, int threshold);

    void begin();
    int read();
    bool isDangerous();
};

#endif