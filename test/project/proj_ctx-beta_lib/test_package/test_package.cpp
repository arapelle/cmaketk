#include <proj_ctx/beta_lib/tools.hpp>

#include <cstdlib>
#include <cassert>

int main()
{
    assert(proj_ctx::beta_lib::decorate("Title") == "_-* Title *-_");
    return EXIT_SUCCESS;
}
