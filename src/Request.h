#pragma once

#include "Constants.h"

#include <jsoncpp/json/value.h>

#include <optional>
#include <string>
#include <variant>

namespace JsonRpc {
/// Запрос JSON-RPC
struct Request {
    /// Оператор преобразования запроса в строку
    explicit operator std::string() const;

    /// Версия протокола JSON-RPC
    std::string jsonRpc = defaultJsonRpcVersion;

    /// Имя метода
    std::string method;

    /// Параметры метода (опц.)
    std::optional<Json::Value> params;

    /// Идентификатор запроса (опц.)
    std::optional<std::variant<int, std::string>> id;
};
} // namespace JsonRpc
