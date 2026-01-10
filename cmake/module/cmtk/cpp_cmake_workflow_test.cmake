include(${CMAKE_CURRENT_LIST_DIR}/utility.cmake)

function(cmtk_add_cpp_cmake_workflow_gtests project gtest_target)
    # Args:
    set(options "")
    set(params "TARGET;TEST_SOURCE;CXX_STANDARD;SOURCE_DIR;BUILD_DIR;INSTALL_DIR;TEST_PACKAGE_SOURCE_DIR;TEST_PACKAGE_BUILD_DIR;PACKAGE_TYPE;UNINSTALL_SCRIPT_SUBPATH;CMAKECC_TARGET")
    set(lists "LINK_LIBRARIES")
    # Parse args:
    cmake_parse_arguments(PARSE_ARGV 1 "ARG" "${options}" "${params}" "${lists}")
    cmtk_set_ifndef(ARG_TARGET "${project}_tests")
    cmtk_set_ifndef(ARG_TEST_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/${ARG_TARGET}.cpp")
    cmtk_assert(EXISTS ${ARG_TEST_SOURCE})
    cmtk_set_ifndef(ARG_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${project}")
    cmtk_assert(EXISTS ${ARG_SOURCE_DIR})
    cmtk_set_ifndef(ARG_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/build/${project}")
    cmtk_set_ifndef(ARG_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/install/${project}")
    cmtk_set_ifndef(ARG_TEST_PACKAGE_SOURCE_DIR "${ARG_SOURCE_DIR}/test_package")
    cmtk_set_ifndef(ARG_TEST_PACKAGE_BUILD_DIR "${ARG_BUILD_DIR}/test_package")
    cmtk_set_ifndef(ARG_CMAKECC_TARGET "cmakecc::cmakecc")
    cmtk_assert(TARGET ${gtest_target})
    cmtk_assert(TARGET ${ARG_CMAKECC_TARGET})
    if(NOT DEFINED ARG_UNINSTALL_SCRIPT_SUBPATH AND DEFINED ARG_PACKAGE_TYPE)
        cmtk_fatal_if_none_of(ARG_PACKAGE_TYPE "bin" "lib")
        cmtk_set_ifndef(ARG_UNINSTALL_SCRIPT_SUBPATH "${ARG_PACKAGE_TYPE}/cmake/${project}/uninstall.cmake")
    endif()
    cmtk_set_ifndef(ARG_CXX_STANDARD 20)
    string(JOIN "|" pipe_module_path ${CMAKE_MODULE_PATH})
    string(JOIN "|" pipe_prefix_path ${CMAKE_PREFIX_PATH})
    add_executable(${ARG_TARGET} ${ARG_TEST_SOURCE})
    target_link_libraries(${ARG_TARGET} PRIVATE ${gtest_target} ${ARG_CMAKECC_TARGET} ${ARG_LINK_LIBRARIES})
    target_compile_features(${ARG_TARGET} PRIVATE cxx_std_${ARG_CXX_STANDARD})
    target_compile_definitions(${ARG_TARGET} PRIVATE
        CMAKE_COMMAND="${CMAKE_COMMAND}"
        CMAKE_CTEST_COMMAND="${CMAKE_CTEST_COMMAND}"
        SOURCE_DIR="${ARG_SOURCE_DIR}"
        BUILD_DIR="${ARG_BUILD_DIR}"
        CMAKE_MODULE_PATH="${pipe_module_path}"
        CMAKE_PREFIX_PATH="${pipe_prefix_path}"
        INSTALL_DIR="${ARG_INSTALL_DIR}"
        TEST_PACKAGE_SOURCE_DIR="${ARG_TEST_PACKAGE_SOURCE_DIR}"
        TEST_PACKAGE_BUILD_DIR="${ARG_TEST_PACKAGE_BUILD_DIR}"
    )
    if(DEFINED ARG_UNINSTALL_SCRIPT_SUBPATH)
        target_compile_definitions(${ARG_TARGET} PRIVATE UNINSTALL_SCRIPT_PATH="${ARG_INSTALL_DIR}/${ARG_UNINSTALL_SCRIPT_SUBPATH}")
    endif()
    gtest_discover_tests(${ARG_TARGET})
endfunction()
