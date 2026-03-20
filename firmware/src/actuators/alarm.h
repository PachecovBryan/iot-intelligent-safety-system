#ifndef ALARM_H
#define ALARM_H

class Alarm {
  private:
    int buzzerPin;
    int ledPin;

  public:
    Alarm(int buzzerPin, int ledPin);
    void activate();
    void deactivate();
};

#endif