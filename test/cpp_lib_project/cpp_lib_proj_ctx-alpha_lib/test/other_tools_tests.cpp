#include <cpp_lib_proj_ctx/alpha_lib/tools.hpp>

#include <gtest/gtest.h>
#include <format>


TEST(unit_tests, test__)
{
    std::string_view str = "coucou";
    const std::string expected_decorated_str = std::format("[[{}]]", str);
    const std::string dstr = cpp_lib_proj_ctx::alpha_lib::decorate(str);
    ASSERT_EQ(cpp_lib_proj_ctx::alpha_lib::decorate(dstr), expected_decorated_str);
}
