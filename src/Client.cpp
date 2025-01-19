#include "Client.h"
//#include "ResponseUnpacker.h"
//#include "Exceptions.h"

namespace JsonRpc {
Client::Client(ISenderPtr sender, IReceiverPtr receiver)
    : _sender(std::move(sender))
    , _receiver(std::move(receiver)) {
    if (!_sender)
        throw std::runtime_error("Invalid sender");

    if (!_receiver)
        throw std::runtime_error("Invalid receiver");

    _receiver->SetCallback([this](const std::string& message) { HandleResponse(message); });
}

bool Client::Send(const Request& request) {
    return _sender->Send(static_cast<std::string>(request));
}

void Client::SetCallback(Callback callback) {
    _callback = std::move(callback);
}

void Client::HandleResponse(std::string_view /*message*/) {
    Response response;

//    try {
//        response = ResponseUnpacker::Unpack(message);
//    }
//    catch (const ParseError&) {
//        response.error = Error(ErrorCode::ParseError);
//    }
//    catch (const InternalError&) {
//        response.error = Error(ErrorCode::InternalError);
//    }
//    catch (...) {
//        response.error = Error(ErrorCode::UnknownError);
//    }

    if (_callback)
        _callback(response);
}
} // namespace JsonRpc
