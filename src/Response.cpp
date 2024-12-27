#include "Response.h"
//#include "IdVisitor.h"

#include <jsoncpp/json/writer.h>

namespace JsonRpc {
Response::operator std::string() const {
    Json::Value value;

    value[Fields::Response::jsonrpc] = jsonRpc;

    if (result)
        value[Fields::Response::result] = *result;

//    if (error)
//        value[Fields::Response::error] = static_cast<Json::Value>(*error);

//    if (id)
//        value[Fields::Request::id] = boost::apply_visitor(IdVisitor(), *id);

    return Json::FastWriter().write(value);
}

//bool operator == (const Response& lhs, const Response& rhs)
//{
//    return std::tie(lhs.jsonRpc, lhs.result, lhs.error, lhs.id) == std::tie(rhs.jsonRpc, rhs.result, rhs.error, rhs.id);
//}
} // namespace JsonRpc
