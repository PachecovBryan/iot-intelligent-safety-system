#ifndef FLAME_SENSOR_H
#define FLAME_SENSOR_H

class FlameSensor {
  private:
    int pin;

  public:
    FlameSensor(int pin);

    void begin();
    bool detected();
};

#endif