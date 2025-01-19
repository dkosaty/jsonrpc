#pragma once

#include "ISender.h"
#include "IReceiver.h"
#include "Request.h"
#include "Response.h"

#include <string_view>

namespace JsonRpc {
/// Клиент JSON-RPC
class Client {
public:
    using Callback = std::function<void(const Response&)>;

public:
    /// Отправляет запросы через sender, принимает ответы через receiver
    Client(ISenderPtr sender, IReceiverPtr receiver);

    /// Отправляет запрос
    bool Send(const Request& request);

    /// Устанавливает функцию ответа
    void SetCallback(Callback callback);

protected:
    /// Обрабатывает ответ
    void HandleResponse(std::string_view message);

private:
    /// Отправитель сообщений
    ISenderPtr _sender;

    /// Получатель сообщений
    IReceiverPtr _receiver;

    /// Функция ответа
    Callback _callback;
};
} // namespace JsonRpc
