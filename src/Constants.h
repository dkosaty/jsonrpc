#pragma once

namespace JsonRpc
{
constexpr const char* const defaultJsonRpcVersion = "2.0";

namespace Fields
{
namespace Request
{
constexpr const char* const jsonrpc = "jsonrpc";
constexpr const char* const method = "method";
constexpr const char* const params = "params";
constexpr const char* const id = "id";
} // namespace Request

namespace Response
{
constexpr const char* const jsonrpc = "jsonrpc";
constexpr const char* const result = "result";
constexpr const char* const error = "error";
constexpr const char* const id = "id";
} // namespace Response

namespace Error
{
constexpr const char* const code = "code";
constexpr const char* const message = "message";
constexpr const char* const data = "data";
} // namespace Error
} // namespace Fields
} // namespace JsonRpc
