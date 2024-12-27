#pragma once

#include "Constants.h"
//#include "Error.h"

#include <jsoncpp/json/value.h>

#include <optional>
#include <string>
#include <variant>

namespace JsonRpc {
/// Ответ на запрос JSON-RPC
struct Response {
    /// Оператор преобразования ответа в строку
    explicit operator std::string() const;

    /// Версия протокола JSON-RPC
    std::string jsonRpc = defaultJsonRpcVersion;

    /**
     * @brief Результат запроса
     * @details Отсутствует в случае неуспешного вызова метода
     */
    std::optional<Json::Value> result;

    /**
     * @brief Ошибка запроса
     * @details Отсутствует в случае успешного вызова метода
     */
//    std::optional<Error> error;

    /// Идентификатор запроса (опц.)
    std::optional<std::variant<int, std::string>> id;
};

//bool operator == (const Response& lhs, const Response& rhs);
} // namespace JsonRpc
