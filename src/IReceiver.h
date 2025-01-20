#pragma once

#include <functional>
#include <memory>
#include <string_view>

namespace JsonRpc {
/// Абстрактный получатель сообщений
class IReceiver {
public:
    using Callback = std::function<void(std::string_view)>;

public:
    virtual ~IReceiver() = default;

    /// Устанавливает функцию обратного вызова
    virtual bool SetCallback(Callback callback) = 0;
};

using IReceiverPtr = std::shared_ptr<IReceiver>;
} // namespace JsonRpc
