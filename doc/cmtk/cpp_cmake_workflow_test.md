
# Cpp CMake Workflow Test

## Include
`find_package(cmaketk COMPONENTS cpp_cmake_workflow_test)`

## Functions
### Function `cmtk_add_cpp_cmake_workflow_gtests(project gtest_target ...)`

&ensp;&ensp;&ensp;&ensp;Create Google tests (by using gtest_discover_tests()) and define compile definitions. These defitions are used for testing 
the CMake workflow of a project (configure, build, test, install, test package). Here is the compile definition list:
- CMAKE_COMMAND : Path to the CMake CLI tool.
- CMAKE_CTEST_COMMAND : Path to the CTest CLI tool.
- SOURCE_DIR : Source directory to the project to test.
- BUILD_DIR : Build directory to compile the project to test.
- CMAKE_MODULE_PATH : List of CMake module directory paths (separated by a pipe, and well handled by cmaketk::cmake_tools classes).
- CMAKE_PREFIX_PATH : List of CMake prefix directory paths (separated by a pipe, and well handled by cmaketk::cmake_tools classes).
- INSTALL_DIR : Directory where the tested project is installed.
- TEST_PACKAGE_SOURCE_DIR : Source directory to the test package of the project to test.
- TEST_PACKAGE_BUILD_DIR : Build directory to compile the test package of the project to test.
- UNINSTALL_SCRIPT_PATH : Path to the uninstall script of the project to test.

&ensp;&ensp;&ensp;&ensp;Positional arguments:
- *project*:  The project name.
- *gtest_target*:  The google test target to link with (gtest, gtest_main, gmock or gmock_main).

&ensp;&ensp;&ensp;&ensp;Optional arguments:
- [TARGET *target*] : The name of the test target to create. (default: ${project}_tests)
- [TEST_SOURCE *source_file*] : The unit test source file. (default: ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET}.cpp)
- [CXX_STANDARD *cxx_std*] : C++ version used (..., 11, 14, 17, 20, 23, 26, ...)
- [SOURCE_DIR *dir*] : Source directory to the project to test. (default: ${CMAKE_CURRENT_SOURCE_DIR}/${project})
- [BUILD_DIR *dir*] : Build directory to compile the project to test. (default: ${CMAKE_CURRENT_BINARY_DIR}/build/${project})
- [INSTALL_DIR *dir*] : Directory where the tested project is installed. (default: ${CMAKE_CURRENT_BINARY_DIR}/install/${project})
- [TEST_PACKAGE_SOURCE_DIR *dir*] : Source directory to the test package of the project to test. (default: ${SOURCE_DIR}/test_package)
- [TEST_PACKAGE_BUILD_DIR *dir*] : Build directory to compile the test package of the project to test. (default: ${BUILD_DIR}/test_package)
- [UNINSTALL_SCRIPT_SUBPATH *dir*] : Relative path to the uninstall script of the project to test. (default if PACKAGE_TYPE provided: ${PACKAGE_TYPE}/cmake/${project}/uninstall.cmake)
- [PACKAGE_TYPE *package_type*] : Package type of the project to test : "bin" or "lib". (used to determine default UNINSTALL_SCRIPT_SUBPATH.)
- [CMAKETK_TARGET *target*] : The cmaketk target to link to. (default: cmaketk::cmake_tools)
- [LINK_LIBRARIES *link_library_targets*]: The list of targets to link to..
