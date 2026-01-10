#include <cpp_proj_ctx/alpha_lib/tools.hpp>

#include <cstdlib>
#include <cassert>

int main()
{
    assert(cpp_proj_ctx::alpha_lib::decorate("Title") == "_-* Title *-_");
    return EXIT_SUCCESS;
}
