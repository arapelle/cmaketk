#include <cmaketk/cmake_tools/cmake_tools.hpp>

#include <gtest/gtest.h>
#include <format>

cmake_tools::cmake cmake(CMAKE_COMMAND);

TEST(proj_alpha_lib_tests, configure__ok)
{
    const int res = cmake.configure(SOURCE_DIR,
                                    BUILD_DIR,
                                    CMAKE_MODULE_PATH,
                                    CMAKE_PREFIX_PATH,
                                    INSTALL_DIR);
    ASSERT_EQ(res, 0);
}

TEST(proj_alpha_lib_tests, build__ok)
{
    const int res = cmake.build(BUILD_DIR);
    ASSERT_EQ(res, 0);
}

TEST(proj_alpha_lib_tests, install__ok)
{
    const int res = cmake.install(BUILD_DIR);
    ASSERT_EQ(res, 0);
}

TEST(proj_alpha_lib_tests, test_package__ok)
{
    int res = cmake.configure(TEST_PACKAGE_SOURCE_DIR,
                              TEST_PACKAGE_BUILD_DIR,
                              CMAKE_MODULE_PATH,
                              std::format("{};{}", INSTALL_DIR, CMAKE_PREFIX_PATH));
    ASSERT_EQ(res, 0);
    res = cmake.build(TEST_PACKAGE_BUILD_DIR);
    ASSERT_EQ(res, 0);
}

TEST(proj_alpha_lib_tests, uninstall__ok)
{
    const int res = cmake.uninstall(UNINSTALL_SCRIPT_PATH);
    ASSERT_EQ(res, 0);
    ASSERT_TRUE(!std::filesystem::exists(UNINSTALL_SCRIPT_PATH));
}
