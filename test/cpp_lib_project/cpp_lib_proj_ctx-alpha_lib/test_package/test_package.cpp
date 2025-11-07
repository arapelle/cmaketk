#include <cpp_lib_proj_ctx/alpha_lib/tools.hpp>

#include <cstdlib>
#include <cassert>

int main()
{
    assert(cpp_lib_proj_ctx::alpha_lib::decorate("Title") == "[Title]");
    return EXIT_SUCCESS;
}
