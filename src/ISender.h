#pragma once

#include <memory>
#include <string>

namespace JsonRpc {
/// Абстрактный отправитель сообщений
class ISender {
public:
    virtual ~ISender() = default;

    /// Отправляет сообщение
    virtual bool Send(const std::string& message) = 0;
};

using ISenderPtr = std::shared_ptr<ISender>;
} // namespace JsonRpc
