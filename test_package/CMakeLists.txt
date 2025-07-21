cmake_minimum_required(VERSION 3.15)

project(PackageTest CXX)

find_package(cmaketk CONFIG REQUIRED COMPONENTS utility)

add_executable(test_package test_package.cpp)
target_compile_features(test_package PRIVATE cxx_std_20)

set_ifndef(TOTO 42)
cmake_print_variables(TOTO)
set_ifndef(TOTO 43)
cmake_print_variables(TOTO)
