cmake_minimum_required(VERSION 3.30)

project(PackageTest CXX)

set(package_name "cpp_proj_ctx-alpha_lib")

find_package(${package_name} CONFIG REQUIRED)

set(executable_name "test_package")
add_executable(${executable_name} ${executable_name}.cpp)
target_link_libraries(${executable_name}
    PRIVATE
        ${package_name}::${package_name}
)
