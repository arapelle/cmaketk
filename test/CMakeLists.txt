
include(GoogleTest)

find_package(GTest 1.14 CONFIG REQUIRED)
find_package(cmake_cpptk 0.1.0 CONFIG REQUIRED)

set(${PACKAGE_NAME}_TEST_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/install/${PACKAGE_NAME}")

string(JOIN "|" pipe_module_path ${CMAKE_MODULE_PATH})
string(JOIN "|" pipe_prefix_path ${CMAKE_PREFIX_PATH})

set(target_name "${PACKAGE_NAME}_tests")
add_executable(${target_name} ${target_name}.cpp)
target_link_libraries(${target_name} PRIVATE GTest::gtest_main cmake_cpptk::cmake_cpptk)
target_compile_features(${target_name} PRIVATE cxx_std_20)
target_compile_definitions(${target_name} PRIVATE
    CMAKE_COMMAND="${CMAKE_COMMAND}"
    SOURCE_DIR="${CMAKE_SOURCE_DIR}"
    BUILD_DIR="${CMAKE_CURRENT_BINARY_DIR}/build/${PACKAGE_NAME}"
    CMAKE_MODULE_PATH="${pipe_module_path}"
    CMAKE_PREFIX_PATH="${pipe_prefix_path}"
    INSTALL_DIR="${${PACKAGE_NAME}_TEST_INSTALL_DIR}"
    TEST_PACKAGE_SOURCE_DIR="${CMAKE_SOURCE_DIR}/test_package/"
    TEST_PACKAGE_BUILD_DIR="${CMAKE_CURRENT_BINARY_DIR}/build/${PACKAGE_NAME}/test_package/"
    UNINSTALL_SCRIPT_PATH="${${PACKAGE_NAME}_TEST_INSTALL_DIR}/lib/cmake/${PACKAGE_NAME}/uninstall.cmake"
)
gtest_discover_tests(${target_name})

list(APPEND CMAKE_PREFIX_PATH "${${PACKAGE_NAME}_TEST_INSTALL_DIR}")
add_subdirectory(utility)
add_subdirectory(project)
add_subdirectory(cpp_project)
add_subdirectory(cpp_lib_project)
add_subdirectory(cpp_exe_project)
add_subdirectory(logging)
add_subdirectory(rsc_cpp_lib_project)
