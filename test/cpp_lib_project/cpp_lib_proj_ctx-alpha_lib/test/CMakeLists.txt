include(GoogleTest)

find_package(GTest 1.14 CONFIG REQUIRED)

# cmtk_add_cpp_library_basic_gtests()
cmtk_add_cpp_library_basic_gtests(${PROJECT_NAME} GTest::gtest_main
    SOURCES
        tools_tests.cpp
)

# cmtk_add_cpp_library_gtest()
cmtk_add_cpp_library_gtest(other_tools_tests ${PROJECT_NAME} GTest::gtest_main
    SOURCES
        other_tools_tests.cpp
)
