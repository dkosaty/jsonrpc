#include "Response.h"
#include "IdVisitor.h"

#include <jsoncpp/json/writer.h>

namespace JsonRpc {
Response::operator std::string() const {
    Json::Value jsonValue;

    jsonValue[Fields::Response::jsonrpc] = jsonRpc;

    if (result)
        jsonValue[Fields::Response::result] = *result;

//    if (error)
//        jsonValue[Fields::Response::error] = static_cast<Json::Value>(*error);

    if (id)
        jsonValue[Fields::Request::id] = std::visit(IdVisitor{}, *id);

    return Json::FastWriter().write(jsonValue);
}

//bool operator == (const Response& lhs, const Response& rhs)
//{
//    return std::tie(lhs.jsonRpc, lhs.result, lhs.error, lhs.id) == std::tie(rhs.jsonRpc, rhs.result, rhs.error, rhs.id);
//}
} // namespace JsonRpc
