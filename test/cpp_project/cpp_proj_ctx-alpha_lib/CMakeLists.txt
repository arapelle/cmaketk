cmake_minimum_required(VERSION 3.30)

include(CMakePrintHelpers)
include(cmtk/cpp_project)

cmtk_check_in_source_build()

cmtk_set_build_type_ifndef()

cmtk_set_package_name(CONTEXT_NAME "cpp_proj_ctx" SUBJECT_NAME "alpha_lib")
cmtk_set_project_name(CONTEXT_NAME "cpp_proj_ctx" SUBJECT_NAME "alpha_lib")

cmtk_set_package_semantic_version(1.2.3)

project(${PACKAGE_NAME}
    VERSION ${PACKAGE_VERSION}
    LANGUAGES CXX
)

# cmtk_cxx_standard_option() MIN MAX
cmtk_cxx_standard_option(${PACKAGE_UPPER_VAR_NAME}_CXX_STANDARD MIN 20 MAX 26)

# cmtk_configure_headers()
cmtk_configure_headers(configured_headers
    FILES
        include/cpp_proj_ctx/alpha_lib/tools.hpp.in
)
# cmtk_configure_sources()
cmtk_configure_sources(configured_sources
    FILES
        src/cpp_proj_ctx/alpha_lib/tools.cpp.in
)
add_library(${PROJECT_NAME} STATIC ${configured_sources})
target_sources(${PROJECT_NAME} PUBLIC FILE_SET HEADERS
    BASE_DIRS
        include
        ${CMAKE_CURRENT_BINARY_DIR}/include
    FILES
        ${configured_headers}
)

cmtk_install_targets(TARGETS ${PROJECT_NAME} EXPORT ${PACKAGE_NAME}-targets NAMESPACE "${PACKAGE_NAME}::")

cmtk_install_package(${PACKAGE_NAME} INPUT_PACKAGE_CONFIG_FILE package-config.cmake.in)

cmtk_install_uninstall_script(${PACKAGE_NAME} LIB)
