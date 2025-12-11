cmake_minimum_required(VERSION 3.30)

include(CMakePrintHelpers)
include(cmtk/project)

# cmtk_check_in_source_build()
cmtk_check_in_source_build()

# cmtk_set_build_type_ifndef()
cmtk_set_build_type_ifndef()

# cmtk_set_package_name() CONTEXT_NAME SUBJECT_NAME
cmtk_set_package_name(CONTEXT_NAME "proj_ctx" SUBJECT_NAME "beta_lib")
cmtk_assert(PACKAGE_NAME STREQUAL "proj_ctx-beta_lib")
cmtk_assert(PACKAGE_CODE_NAME STREQUAL "proj_ctx-beta_lib")
cmtk_assert(PACKAGE_CONTEXT_NAME STREQUAL "proj_ctx")
cmtk_assert(PACKAGE_SUBJECT_NAME STREQUAL "beta_lib")
cmtk_assert(PACKAGE_CODE_CONTEXT_NAME STREQUAL "proj_ctx")
cmtk_assert(PACKAGE_CODE_SUBJECT_NAME STREQUAL "beta_lib")
cmtk_assert(PACKAGE_UPPER_VAR_NAME STREQUAL "PROJ_CTX_BETA_LIB")
cmtk_assert(PACKAGE_LOWER_VAR_NAME STREQUAL "proj_ctx_beta_lib")

# cmtk_set_project_name() CONTEXT_NAME SUBJECT_NAME
cmtk_set_project_name(CONTEXT_NAME "proj_ctx" SUBJECT_NAME "beta_lib")
cmtk_assert(PROJECT_NAME STREQUAL "proj_ctx-beta_lib")
cmtk_assert(PROJECT_CODE_NAME STREQUAL "proj_ctx-beta_lib")
cmtk_assert(PROJECT_CONTEXT_NAME STREQUAL "proj_ctx")
cmtk_assert(PROJECT_SUBJECT_NAME STREQUAL "beta_lib")
cmtk_assert(PROJECT_CODE_CONTEXT_NAME STREQUAL "proj_ctx")
cmtk_assert(PROJECT_CODE_SUBJECT_NAME STREQUAL "beta_lib")
cmtk_assert(PROJECT_UPPER_VAR_NAME STREQUAL "PROJ_CTX_BETA_LIB")
cmtk_assert(PROJECT_LOWER_VAR_NAME STREQUAL "proj_ctx_beta_lib")

# cmtk_set_package_semantic_version() X.Y.Z
cmtk_set_package_semantic_version(1.2.3)

project(${PACKAGE_NAME}
    VERSION ${PACKAGE_VERSION}
    LANGUAGES CXX
)

# cmtk_configure_files()
cmtk_configure_files(configured_headers
    BASE_DIR
        include
    BINARY_BASE_DIR
        ${CMAKE_CURRENT_BINARY_DIR}/include
    FILES
        include/proj_ctx/beta_lib/tools.hpp.in
)
cmtk_configure_files(configured_sources
    BASE_DIR
        src
    BINARY_BASE_DIR
        ${CMAKE_CURRENT_BINARY_DIR}/src
    FILES
        src/proj_ctx/beta_lib/tools.cpp.in
)
add_library(${PROJECT_NAME} STATIC ${configured_sources})
target_sources(${PROJECT_NAME} PUBLIC FILE_SET HEADERS
    BASE_DIRS
        include
        ${CMAKE_CURRENT_BINARY_DIR}/include
    FILES
        ${configured_headers}
)

# cmtk_install_targets()
cmtk_install_targets(TARGETS ${PROJECT_NAME} EXPORT ${PACKAGE_NAME}-targets NAMESPACE "${PACKAGE_NAME}::")

# cmtk_install_package()
cmtk_install_package(${PACKAGE_NAME} INPUT_PACKAGE_CONFIG_FILE package-config.cmake.in)

# cmtk_install_uninstall_script()
cmtk_install_uninstall_script(${PACKAGE_NAME} LIB)
