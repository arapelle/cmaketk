#pragma once

#include <string_view>
#include <span>

inline namespace rsc_cpp_lib_proj_ctx
{
namespace alpha_lib
{
std::span<const std::byte> get_serialized_resource(std::string_view rsc_path);
} // namespace alpha_lib
} // namespace rsc_cpp_lib_proj_ctx
