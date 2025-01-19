#include "Server.h"
//#include "RequestUnpacker.h"
//#include "Exceptions.h"

namespace JsonRpc {
Server::Server(ISenderPtr sender, IReceiverPtr receiver)
    : _sender(std::move(sender))
    , _receiver(std::move(receiver)) {
    if (!_sender)
        throw std::runtime_error("Invalid sender");

    if (!_receiver)
        throw std::runtime_error("Invalid receiver");

    _receiver->SetCallback([this](const std::string & message) { HandleRequest(message); });
}

void Server::SetCallback(Callback callback) {
    _callback = std::move(callback);
}

void Server::HandleRequest(std::string_view /*message*/) {
    Response response;

//    try {
//        if (_callback)
//            response = _callback(RequestUnpacker::Unpack(message));
//    }
//    catch (const ParseError&) {
//        response.error = Error(ErrorCode::ParseError);
//    }
//    catch (const InvalidRequestError&) {
//        response.error = Error(ErrorCode::InvalidRequest);
//    }
//    catch (const MethodNotFoundError&) {
//        response.error = Error(ErrorCode::MethodNotFound);
//    }
//    catch (const InvalidParamsError&) {
//        response.error = Error(ErrorCode::InvalidParams);
//    }
//    catch (const InternalError&) {
//        response.error = Error(ErrorCode::InternalError);
//    }
//    catch (...) {
//        response.error = Error(ErrorCode::UnknownError);
//    }

    Send(response);
}

bool Server::Send(const Response& response) {
    return _sender->Send(static_cast<std::string>(response));
}
} // namespace JsonRpc
