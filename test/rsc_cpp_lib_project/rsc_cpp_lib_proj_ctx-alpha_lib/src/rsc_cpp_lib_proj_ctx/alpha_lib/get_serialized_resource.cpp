#include <rsc_cpp_lib_proj_ctx/alpha_lib/get_serialized_resource.hpp>
#include <rsc_cpp_lib_proj_ctx/alpha_lib/find_serialized_resource.hpp>
#include <format>
#include <string>
#include <stdexcept>

inline namespace rsc_cpp_lib_proj_ctx
{
namespace alpha_lib
{
std::span<const std::byte> get_serialized_resource(std::string_view rsc_path)
{
    std::optional bytes_o = find_serialized_resource(rsc_path);
    if (bytes_o)
        return *bytes_o;
    throw std::runtime_error(std::format("Serialized resource not found: {}", rsc_path));
}
} // alpha_lib
} // cpp_lib_proj_ctx
