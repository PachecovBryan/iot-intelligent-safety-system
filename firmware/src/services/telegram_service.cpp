#include "telegram_service.h"

TelegramService::TelegramService(const char* token, const char* chat_id)
    : bot(token, client) {
    this->chat_id = chat_id;
}

void TelegramService::begin() {
    client.setInsecure();
}

void TelegramService::sendMessage(String msg) {
    bot.sendMessage(chat_id, msg, "");
}

int TelegramService::getUpdates() {
    return bot.getUpdates(bot.last_message_received + 1);
}

String TelegramService::getMessageText(int i) {
    return bot.messages[i].text;
}