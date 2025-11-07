#include <proj_alpha_lib/tools.hpp>

#include <cstdlib>
#include <cassert>

int main()
{
    assert(proj_alpha_lib::decorate("Title") == "_-* Title *-_");
    return EXIT_SUCCESS;
}
