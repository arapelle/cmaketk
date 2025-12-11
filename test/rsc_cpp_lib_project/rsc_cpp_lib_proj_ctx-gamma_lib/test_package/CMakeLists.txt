cmake_minimum_required(VERSION 3.30)

project(PackageTest CXX)

set(package_name "rsc_cpp_lib_proj_ctx-gamma_lib")

find_package(${package_name} CONFIG REQUIRED)

set(executable_name "test_package")
add_executable(${executable_name} ${executable_name}.cpp)
target_link_libraries(${executable_name}
    PRIVATE
        ${package_name}::${package_name}
)
