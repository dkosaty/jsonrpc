#include "Request.h"
#include "IdVisitor.h"

#include <jsoncpp/json/writer.h>

namespace JsonRpc {
Request::operator std::string() const {
    Json::Value jsonValue;

    jsonValue[Fields::Request::jsonrpc] = jsonRpc;

    jsonValue[Fields::Request::method] = method;

    if (params)
        jsonValue[Fields::Request::params] = *params;

    if (id)
        jsonValue[Fields::Request::id] = std::visit(IdVisitor{}, *id);

    return Json::FastWriter().write(jsonValue);
}
} // namespace JsonRpc
