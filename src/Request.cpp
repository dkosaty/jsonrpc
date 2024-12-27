#include "Request.h"
//#include "IdVisitor.h"

#include <jsoncpp/json/writer.h>

namespace JsonRpc {
Request::operator std::string() const {
    Json::Value json;

    json[Fields::Request::jsonrpc] = jsonRpc;

    json[Fields::Request::method] = method;

    if (params)
        json[Fields::Request::params] = *params;

//    if (id)
//        json[Fields::Request::id] = boost::apply_visitor(IdVisitor(), *id);

    return Json::FastWriter().write(json);
}
} // namespace JsonRpc
