#include "telegram_handler.h"

TelegramHandler::TelegramHandler(TelegramService& t, SystemController& c)
    : telegram(t), controller(c) {}

void TelegramHandler::update() {
    int nuevos = telegram.getUpdates();

    while (nuevos) {
        for (int i = 0; i < nuevos; i++) {

            String txt = telegram.getMessageText(i);
            txt.trim();
            txt.toLowerCase();

            controller.handleCommand(txt);
        }

        nuevos = telegram.getUpdates();
    }
}