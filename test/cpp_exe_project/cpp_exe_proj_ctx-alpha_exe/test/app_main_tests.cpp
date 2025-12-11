#include <cpp_exe_proj_ctx/alpha_exe/app_main.hpp>

#include <gtest/gtest.h>
#include <format>
#include <iostream>

TEST(app_main_tests, test_app_main)
{
    std::stringstream buffer;
    std::streambuf* cout_buf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    std::array args = { "/path/to/we/don't/care", "coucou" };
    int res = cpp_exe_proj_ctx::alpha_exe::app_main(args.size(), const_cast<char**>(args.data()));
    std::cout.rdbuf(cout_buf);
    ASSERT_EQ(res, 0);

    const std::string output_str = buffer.str();
    ASSERT_EQ(output_str.find("[coucou]"), 0);
}
