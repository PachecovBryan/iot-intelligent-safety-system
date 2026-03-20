#ifndef CONFIG_H
#define CONFIG_H

// WIFI
#define SSID "TU_WIFI"
#define PASS "TU_PASSWORD"

// TELEGRAM
#define BOTtoken "TU_BOT_TOKEN"
#define CHAT_ID "TU_CHAT_ID"

// PINES
#define sensorGas 34
#define DHTPIN 17
#define sensorLlama 16

#define extractor 6
#define buzzer 5
#define ledRojo 7
#define ledVerde 4

// UMBRALES SENSORES
#define UMBRAL_GAS 300
#define UMBRAL_TEMP 40

// TIEMPOS
#define intervaloAlerta 30000       // 30 segundos
#define intervaloTempLectura 2000   // 2 segundos

#endif