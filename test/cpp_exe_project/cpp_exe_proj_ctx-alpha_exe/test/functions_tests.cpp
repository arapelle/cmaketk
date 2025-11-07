#include <cpp_exe_proj_ctx/alpha_exe/tools.hpp>

#include <gtest/gtest.h>
#include <format>

TEST(functions_tests, test_function)
{
    std::string_view str = "coucou";
    std::string expected_decorated_str = std::format("[{}]", str);
    ASSERT_EQ(cpp_exe_proj_ctx::alpha_exe::decorate(str), expected_decorated_str);
}
