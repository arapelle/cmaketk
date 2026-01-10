#include <cpp_exe_proj_ctx/alpha_exe/tools.hpp>

inline namespace cpp_exe_proj_ctx
{
namespace alpha_exe
{
std::string decorate(std::string_view str)
{
    return std::string("[") + std::string(str) + "]";
}
} // alpha_exe
} // cpp_exe_proj_ctx
