cmake_minimum_required(VERSION 3.30)

project(PackageTest CXX)

find_package(cmaketk CONFIG REQUIRED COMPONENTS utility)

add_executable(test_package test_package.cpp)
target_compile_features(test_package PRIVATE cxx_std_20)

cmtk_set_ifndef(IVAR 42)
cmake_print_variables(IVAR)
cmtk_assert(IVAR EQUAL 42)
cmtk_set_ifndef(IVAR 43)
cmake_print_variables(IVAR)
cmtk_assert(IVAR EQUAL 42)
