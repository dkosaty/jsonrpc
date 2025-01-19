#pragma once

#include "ISender.h"
#include "IReceiver.h"
#include "Request.h"
#include "Response.h"

#include <string_view>

namespace JsonRpc {
/// Сервер JSON-RPC
class Server {
public:
    using Callback = std::function<Response(const Request&)>;

public:
    /// Принимает запросы через receiver, отправляет ответы через sender
    Server(ISenderPtr sender, IReceiverPtr receiver);

    /// Устанавливает функцию запроса
    void SetCallback(Callback callback);

protected:
    /// Обрабатывает запрос
    void HandleRequest(std::string_view message);

private:
    /// Отправляет ответ
    bool Send(const Response& response);

private:
    /// Отправитель сообщений
    ISenderPtr _sender;

    /// Получатель сообщений
    IReceiverPtr _receiver;

    /// Функция запроса
    Callback _callback;
};
} // namespace JsonRpc
