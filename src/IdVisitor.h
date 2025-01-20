#pragma once

#include <jsoncpp/json/value.h>

namespace JsonRpc {
struct IdVisitor {
    Json::Value operator()(int i) const {
        return i;
    }

    Json::Value operator()(std::string_view str) {
        return {str.begin(), str.end()};
    }
};
} // namespace JsonRpc
