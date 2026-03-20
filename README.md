# IoT Intelligent Safety System 

Sistema IoT basado en ESP32 para detección temprana de riesgos ambientales (gas, fuego y temperatura), con alertas en tiempo real vía Telegram y activación automática de actuadores.

## Características

-  Detección de gas (MQ2)
-  Detección de fuego (YL-38)
-  Monitoreo de temperatura (DHT11)
-  Notificaciones en tiempo real mediante Telegram
-  Activación automática de extractor
-  Control remoto de sensores desde Telegram
-  Sistema anti-spam de alertas (control por tiempo)

---

## Arquitectura

El sistema está organizado en capas:

### Componentes

- **Sensors** → Lectura de hardware (gas, temperatura, llama)
- **Controller** → Lógica del sistema y toma de decisiones
- **Services** → Comunicación externa (Telegram API)
- **Actuators** → Respuesta física (extractor, LEDs, buzzer)

---

## Hardware utilizado

- ESP32
- Sensor MQ2 (gas)
- Sensor DHT11 (temperatura)
- Sensor YL-38 (llama)
- Buzzer
- LEDs
- Extractor / ventilador

---

## Configuración

Editar el archivo:

Configurar los siguientes valores:

```cpp
#define SSID "TU_WIFI"
#define PASS "TU_PASSWORD"

#define BOTtoken "TU_BOT_TOKEN"
#define CHAT_ID "TU_CHAT_ID"

Instalación

Clonar repositorio:
git clone https://github.com/PachecovBryan/iot-intelligent-safety-system.git

Abrir en Arduino IDE o PlatformIO

Configurar config.h
Subir al ESP32

Comandos disponibles (Telegram)
-monitoreo on
-monitoreo off
-gas on / gas off
-temp on / temp off
-llama on / llama off
-extractor on / extractor off

Ejemplo de alertas
⚠️ Gas detectado: 420
🔥 Fuego detectado
🌡️ Temperatura alta: 41.2 °C

Estructura del proyecto
firmware/
 ├── config/
 ├── src/
 │   ├── sensors/
 │   ├── controller/
 │   ├── services/
 │   ├── actuators/
 │   └── main.cpp

Dashboard web

Integración MQTT

Base de datos de eventos

Aplicación móvil

Detección de anomalías (Machine Learning)


Licencia
MIT License