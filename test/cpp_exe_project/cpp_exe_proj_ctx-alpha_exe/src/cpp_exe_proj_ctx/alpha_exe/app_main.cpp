#include <cpp_exe_proj_ctx/alpha_exe/app_main.hpp>
#include <cpp_exe_proj_ctx/alpha_exe/tools.hpp>

#include <iostream>

inline namespace cpp_exe_proj_ctx
{
namespace alpha_exe
{
int app_main(int argc, char** argv)
{
    std::cout << alpha_exe::decorate(argv[1]);
    return EXIT_SUCCESS;
}
} // alpha_exe
} // cpp_exe_proj_ctx
