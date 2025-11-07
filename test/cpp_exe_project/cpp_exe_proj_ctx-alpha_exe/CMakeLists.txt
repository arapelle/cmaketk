cmake_minimum_required(VERSION 3.30)

include(CMakePrintHelpers)
include(cmtk/cpp_exe_project)

cmtk_check_in_source_build()
cmtk_set_build_type_ifndef()

cmtk_set_package_name(CONTEXT_NAME "cpp_exe_proj_ctx" SUBJECT_NAME "alpha_exe")
cmtk_set_package_semantic_version(1.2.3)

cmtk_set_project_name(CONTEXT_NAME "cpp_exe_proj_ctx" SUBJECT_NAME "alpha_exe")
project(${PACKAGE_NAME}
    VERSION ${PACKAGE_VERSION}
    LANGUAGES CXX
)

cmtk_cxx_standard_option(${PACKAGE_UPPER_VAR_NAME}_CXX_STANDARD MIN 20 MAX 26)

# cmtk_add_cpp_executable()
cmtk_add_cpp_executable(${PROJECT_NAME}
    OBJECT ${PROJECT_NAME}-object
    HEADERS
        include/cpp_exe_proj_ctx/alpha_exe/tools.hpp
        include/cpp_exe_proj_ctx/alpha_exe/app_main.hpp
    SOURCES
        src/cpp_exe_proj_ctx/alpha_exe/tools.cpp
        src/cpp_exe_proj_ctx/alpha_exe/app_main.cpp
    MAIN_SOURCE
        src/cpp_exe_proj_ctx/alpha_exe/main.cpp
    CXX_STANDARD ${${PACKAGE_UPPER_VAR_NAME}_CXX_STANDARD}
    DEFAULT_WARNING_OPTIONS
    DEFAULT_ERROR_OPTIONS
)

cmtk_add_test_subdirectory_if_built(test)
set(${PACKAGE_UPPER_VAR_NAME}_${PROJECT_UPPER_VAR_NAME}_BUILD_TESTS ON)
cmtk_add_test_subdirectory_if_built(test)

cmtk_install_targets(TARGETS ${PROJECT_NAME} EXPORT ${PACKAGE_NAME}-targets NAMESPACE "${PACKAGE_NAME}::")
cmtk_install_package(${PACKAGE_NAME} INPUT_PACKAGE_CONFIG_FILE package-config.cmake.in)
cmtk_install_uninstall_script(${PACKAGE_NAME} BIN)
