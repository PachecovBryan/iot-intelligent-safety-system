#ifndef SYSTEM_CONTROLLER_H
#define SYSTEM_CONTROLLER_H

#include <Arduino.h>

#include "../sensors/gas_sensor.h"
#include "../sensors/temp_sensor.h"
#include "../sensors/flame_sensor.h"
#include "../services/telegram_service.h"
#include "../config/config.h"

class SystemController {
  private:
    // Sensores
    GasSensor& gas;
    TempSensor& temp;
    FlameSensor& flame;

    // Servicio
    TelegramService* telegram;

    // Actuadores
    int extractor;

    // Estados
    bool sistemaActivo;
    bool gasActivo;
    bool tempActivo;
    bool llamaActivo;
    bool extractorOn;
    bool llamaPrevio;

    // Tiempos
    unsigned long ultimaAlertaGas;
    unsigned long ultimaAlertaTemp;
    unsigned long ultimaAlertaLlama;
    unsigned long ultimaLecturaTemp;

  public:
    SystemController(GasSensor& g, TempSensor& t, FlameSensor& f, int extractorPin);

    void setTelegram(TelegramService* t);

    void begin();
    void update();
    void handleCommand(String cmd);
};

#endif