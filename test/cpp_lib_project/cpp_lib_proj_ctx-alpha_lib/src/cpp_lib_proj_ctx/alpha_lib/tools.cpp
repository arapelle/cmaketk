#include <cpp_lib_proj_ctx/alpha_lib/tools.hpp>

inline namespace cpp_lib_proj_ctx
{
namespace alpha_lib
{
std::string decorate(std::string_view str)
{
    return std::string("[") + std::string(str) + "]";
}
} // alpha_lib
} // cpp_lib_proj_ctx
