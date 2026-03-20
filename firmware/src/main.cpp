#include <WiFi.h>
#include <DHT.h>

#include "config/config.h"

// Sensores
#include "sensors/gas_sensor.h"
#include "sensors/temp_sensor.h"
#include "sensors/flame_sensor.h"

// Servicios
#include "services/telegram_service.h"
#include "services/telegram_handler.h"

// Controller
#include "controller/system_controller.h"

// DHT
DHT dht(DHTPIN, DHT11);

// Sensores
GasSensor gas(sensorGas, UMBRAL_GAS);
TempSensor temp(dht, UMBRAL_TEMP);
FlameSensor flame(sensorLlama);

// Servicios
TelegramService telegram(BOTtoken, CHAT_ID);

// Controller
SystemController controller(gas, temp, flame, extractor);

// Handler Telegram
TelegramHandler handler(telegram, controller);

void setup() {
    Serial.begin(115200);

    // Inicializar sensores
    gas.begin();
    temp.begin();
    flame.begin();

    // Pines actuadores
    pinMode(extractor, OUTPUT);
    digitalWrite(extractor, LOW);

    // WiFi
    WiFi.begin(SSID, PASS);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    // Telegram
    telegram.begin();
    telegram.sendMessage("✅ SISTEMA INICIADO");

    // Controller
    controller.setTelegram(&telegram);
    controller.begin();
}

void loop() {
    handler.update();     // Comandos Telegram
    controller.update();  // Lógica del sistema
}