#include "system_controller.h"

SystemController::SystemController(GasSensor& g, TempSensor& t, FlameSensor& f, int extractorPin)
    : gas(g), temp(t), flame(f) {

    extractor = extractorPin;

    sistemaActivo = true;
    gasActivo = true;
    tempActivo = true;
    llamaActivo = true;
    extractorOn = false;

    telegram = nullptr;
}

void SystemController::setTelegram(TelegramService* t) {
    telegram = t;
}

void SystemController::begin() {
    ultimaAlertaGas = 0;
    ultimaAlertaTemp = 0;
    ultimaAlertaLlama = 0;
    ultimaLecturaTemp = 0;

    llamaPrevio = flame.detected();
}

void SystemController::update() {
    unsigned long ahora = millis();

    if (!sistemaActivo) return;

    // GAS
    if (gasActivo && gas.isDangerous() &&
        (ahora - ultimaAlertaGas > intervaloAlerta)) {

        int valor = gas.read();

        Serial.println("ALERTA GAS");

        if (telegram)
            telegram->sendMessage("⚠️ ¡PELIGRO! Gas detectado: " + String(valor));

        ultimaAlertaGas = ahora;

        digitalWrite(extractor, HIGH);
        extractorOn = true;
    }

    // TEMPERATURA
    if (tempActivo && (ahora - ultimaLecturaTemp >= intervaloTempLectura)) {

        float valor = temp.read();

        if (isnan(valor)) {
            Serial.println("Error: lectura temperatura");
        }
        else if (valor > UMBRAL_TEMP &&
                 (ahora - ultimaAlertaTemp > intervaloAlerta)) {

            Serial.println("ALERTA TEMPERATURA");

            if (telegram)
                telegram->sendMessage("🌡️ Temperatura alta: " + String(valor, 1) + " °C");

            ultimaAlertaTemp = ahora;

            digitalWrite(extractor, HIGH);
            extractorOn = true;
        }

        ultimaLecturaTemp = ahora;
    }

    // LLAMA
    if (llamaActivo) {
        bool llama = flame.detected();

        if (llama && !llamaPrevio &&
            (ahora - ultimaAlertaLlama > intervaloAlerta)) {

            Serial.println("ALERTA FUEGO");

            if (telegram)
                telegram->sendMessage("🔥 ¡PELIGRO! Fuego detectado");

            ultimaAlertaLlama = ahora;
        }

        llamaPrevio = llama;
    }
}

void SystemController::handleCommand(String cmd) {
    cmd.trim();
    cmd.toLowerCase();

    if (cmd == "monitoreo on") {
        sistemaActivo = true;
        if (telegram) telegram->sendMessage("✅ Monitoreo ACTIVADO");

    } else if (cmd == "monitoreo off") {
        sistemaActivo = false;
        if (telegram) telegram->sendMessage("⛔ Monitoreo DESACTIVADO");

    } else if (cmd == "gas on") {
        gasActivo = true;
        if (telegram) telegram->sendMessage("⛽ Sensor GAS ACTIVADO");

    } else if (cmd == "gas off") {
        gasActivo = false;
        if (telegram) telegram->sendMessage("⛽ Sensor GAS DESACTIVADO");

    } else if (cmd == "temp on") {
        tempActivo = true;
        if (telegram) telegram->sendMessage("🌡️ Sensor TEMP ACTIVADO");

    } else if (cmd == "temp off") {
        tempActivo = false;
        if (telegram) telegram->sendMessage("🌡️ Sensor TEMP DESACTIVADO");

    } else if (cmd == "llama on") {
        llamaActivo = true;
        if (telegram) telegram->sendMessage("🔥 Sensor LLAMA ACTIVADO");

    } else if (cmd == "llama off") {
        llamaActivo = false;
        if (telegram) telegram->sendMessage("🔥 Sensor LLAMA DESACTIVADO");

    } else if (cmd == "extractor on") {
        digitalWrite(extractor, HIGH);
        extractorOn = true;
        if (telegram) telegram->sendMessage("🌀 Extractor ACTIVADO");

    } else if (cmd == "extractor off") {
        digitalWrite(extractor, LOW);
        extractorOn = false;
        if (telegram) telegram->sendMessage("🌀 Extractor DESACTIVADO");
    }
}