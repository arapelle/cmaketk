include(GoogleTest)

find_package(GTest 1.14 CONFIG REQUIRED)

cmtk_add_cpp_library_basic_gtests(${PROJECT_NAME} GTest::gtest_main
    SOURCES
        unit_tests.cpp
)
