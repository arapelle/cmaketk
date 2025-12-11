cmake_minimum_required(VERSION 3.30)

project(PackageTest CXX)

find_package(cmaketk CONFIG REQUIRED
    COMPONENTS
        cmake_tools
        utility
        logging
        project
        cpp_project
        cpp_lib_project
        cpp_exe_project
        rsc_cpp_lib_project
        cpp_cmake_workflow_test
)

add_executable(test_package test_package.cpp)
target_compile_features(test_package PRIVATE cxx_std_20)
target_link_libraries(test_package PRIVATE cmaketk::cmaketk)

cmtk_set_ifndef(IVAR 42)
cmake_print_variables(IVAR)
cmtk_assert(IVAR EQUAL 42)
cmtk_set_ifndef(IVAR 43)
cmake_print_variables(IVAR)
cmtk_assert(IVAR EQUAL 42)
