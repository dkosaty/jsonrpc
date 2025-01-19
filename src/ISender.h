#pragma once

#include <memory>
#include <string_view>

namespace JsonRpc {
/// Абстрактный отправитель сообщений
class ISender {
public:
    virtual ~ISender() = default;

    /// Отправляет сообщение
    virtual bool Send(std::string_view message) = 0;
};

using ISenderPtr = std::shared_ptr<ISender>;
} // namespace JsonRpc
