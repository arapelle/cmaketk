#include <cpp_lib_proj_ctx/alpha_lib/tools.hpp>

#include <gtest/gtest.h>
#include <format>


TEST(unit_tests, test__)
{
    std::string_view str = "coucou";
    std::string expected_decorated_str = std::format("[{}]", str);
    ASSERT_EQ(cpp_lib_proj_ctx::alpha_lib::decorate(str), expected_decorated_str);
}
