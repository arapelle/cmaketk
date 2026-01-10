include(GoogleTest)

find_package(GTest 1.14 CONFIG REQUIRED)

cmtk_add_cpp_library_basic_gtests(${PROJECT_NAME}-object GTest::gtest_main
    SOURCES
        app_main_tests.cpp
)

cmtk_add_cpp_library_gtest(functions_tests ${PROJECT_NAME}-object GTest::gtest_main
    SOURCES
        functions_tests.cpp
)
