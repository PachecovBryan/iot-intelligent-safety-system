#ifndef TELEGRAM_HANDLER_H
#define TELEGRAM_HANDLER_H

#include "telegram_service.h"
#include "../controller/system_controller.h"

class TelegramHandler {
  private:
    TelegramService& telegram;
    SystemController& controller;

  public:
    TelegramHandler(TelegramService& t, SystemController& c);

    void update();
};

#endif