#ifndef TELEGRAM_SERVICE_H
#define TELEGRAM_SERVICE_H

#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

class TelegramService {
  private:
    WiFiClientSecure client;
    UniversalTelegramBot bot;
    String chat_id;

  public:
    TelegramService(const char* token, const char* chat_id);

    void begin();
    void sendMessage(String msg);

    int getUpdates();
    String getMessageText(int i);
};

#endif