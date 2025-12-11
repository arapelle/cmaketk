cmake_minimum_required(VERSION 3.30)

include(CMakePrintHelpers)
include(cmtk/project)

# cmtk_check_in_source_build()
cmtk_check_in_source_build()

# cmtk_set_build_type_ifndef()
cmtk_set_build_type_ifndef()
cmtk_assert(CMAKE_BUILD_TYPE STREQUAL "Release")

# cmtk_set_package_name() NAME
cmtk_set_package_name(NAME "proj_alpha_lib")
cmtk_assert(PACKAGE_NAME STREQUAL "proj_alpha_lib")
cmtk_assert(PACKAGE_CODE_NAME STREQUAL "proj_alpha_lib")
cmtk_assert(NOT DEFINED PACKAGE_CONTEXT_NAME)
cmtk_assert(NOT DEFINED PACKAGE_SUBJECT_NAME)
cmtk_assert(NOT DEFINED PACKAGE_CODE_CONTEXT_NAME)
cmtk_assert(NOT DEFINED PACKAGE_CODE_SUBJECT_NAME)
cmtk_assert(PACKAGE_UPPER_VAR_NAME STREQUAL "PROJ_ALPHA_LIB")
cmtk_assert(PACKAGE_LOWER_VAR_NAME STREQUAL "proj_alpha_lib")

# cmtk_set_project_name() NAME
cmtk_set_project_name(NAME "proj_alpha_lib")
cmtk_assert(PROJECT_NAME STREQUAL "proj_alpha_lib")
cmtk_assert(PROJECT_CODE_NAME STREQUAL "proj_alpha_lib")
cmtk_assert(NOT DEFINED PROJECT_CONTEXT_NAME)
cmtk_assert(NOT DEFINED PROJECT_SUBJECT_NAME)
cmtk_assert(NOT DEFINED PROJECT_CODE_CONTEXT_NAME)
cmtk_assert(NOT DEFINED PROJECT_CODE_SUBJECT_NAME)
cmtk_assert(PROJECT_UPPER_VAR_NAME STREQUAL "PROJ_ALPHA_LIB")
cmtk_assert(PROJECT_LOWER_VAR_NAME STREQUAL "proj_alpha_lib")

# cmtk_set_package_semantic_version() X.Y.Z
cmtk_set_package_semantic_version(1.2.3)
cmtk_assert(PACKAGE_VERSION STREQUAL "1.2.3")
cmtk_assert(PACKAGE_SEMANTIC_VERSION STREQUAL "1.2.3")
cmtk_assert(PACKAGE_VERSION_MAJOR EQUAL 1)
cmtk_assert(PACKAGE_VERSION_MINOR EQUAL 2)
cmtk_assert(PACKAGE_VERSION_PATCH EQUAL 3)
cmtk_assert("'${PACKAGE_VERSION_PRE_RELEASE}'" STREQUAL "''")
cmtk_assert("'${PACKAGE_VERSION_BUILD_METADATA}'" STREQUAL "''")

# cmtk_set_package_semantic_version() X.Y.Z PRE_RELEASE BUILD_METADATA
cmtk_set_package_semantic_version(4.5.6 PRE_RELEASE "dev" BUILD_METADATA "alphabm")
cmtk_assert(PACKAGE_VERSION STREQUAL "4.5.6")
cmtk_assert(PACKAGE_SEMANTIC_VERSION STREQUAL "4.5.6-dev+alphabm")
cmtk_assert(PACKAGE_VERSION_MAJOR EQUAL 4)
cmtk_assert(PACKAGE_VERSION_MINOR EQUAL 5)
cmtk_assert(PACKAGE_VERSION_PATCH EQUAL 6)
cmtk_assert("'${PACKAGE_VERSION_PRE_RELEASE}'" STREQUAL "'dev'")
cmtk_assert("'${PACKAGE_VERSION_BUILD_METADATA}'" STREQUAL "'alphabm'")

# cmtk_set_package_semantic_version() X.Y.Z PRE_RELEASE
cmtk_set_package_semantic_version(7.8.9 PRE_RELEASE "beta")
cmtk_assert(PACKAGE_VERSION STREQUAL "7.8.9")
cmtk_assert(PACKAGE_SEMANTIC_VERSION STREQUAL "7.8.9-beta")
cmtk_assert(PACKAGE_VERSION_MAJOR EQUAL 7)
cmtk_assert(PACKAGE_VERSION_MINOR EQUAL 8)
cmtk_assert(PACKAGE_VERSION_PATCH EQUAL 9)
cmtk_assert("'${PACKAGE_VERSION_PRE_RELEASE}'" STREQUAL "'beta'")
cmtk_assert("'${PACKAGE_VERSION_BUILD_METADATA}'" STREQUAL "''")

# cmtk_set_package_semantic_version() X.Y.Z BUILD_METADATA
cmtk_set_package_semantic_version(10.11.12 BUILD_METADATA "gammabm")
cmtk_assert(PACKAGE_VERSION STREQUAL "10.11.12")
cmtk_assert(PACKAGE_SEMANTIC_VERSION STREQUAL "10.11.12+gammabm")
cmtk_assert(PACKAGE_VERSION_MAJOR EQUAL 10)
cmtk_assert(PACKAGE_VERSION_MINOR EQUAL 11)
cmtk_assert(PACKAGE_VERSION_PATCH EQUAL 12)
cmtk_assert("'${PACKAGE_VERSION_PRE_RELEASE}'" STREQUAL "''")
cmtk_assert("'${PACKAGE_VERSION_BUILD_METADATA}'" STREQUAL "'gammabm'")

# cmtk_set_project_semantic_version() X.Y.Z
cmtk_set_project_semantic_version(1.2.3)
cmtk_assert(PROJECT_VERSION STREQUAL "1.2.3")
cmtk_assert(PROJECT_SEMANTIC_VERSION STREQUAL "1.2.3")
cmtk_assert(PROJECT_VERSION_MAJOR EQUAL 1)
cmtk_assert(PROJECT_VERSION_MINOR EQUAL 2)
cmtk_assert(PROJECT_VERSION_PATCH EQUAL 3)
cmtk_assert("'${PROJECT_VERSION_PRE_RELEASE}'" STREQUAL "''")
cmtk_assert("'${PROJECT_VERSION_BUILD_METADATA}'" STREQUAL "''")

# cmtk_set_project_semantic_version() X.Y.Z PRE_RELEASE BUILD_METADATA
cmtk_set_project_semantic_version(4.5.6 PRE_RELEASE "dev" BUILD_METADATA "alphabm")
cmtk_assert(PROJECT_VERSION STREQUAL "4.5.6")
cmtk_assert(PROJECT_SEMANTIC_VERSION STREQUAL "4.5.6-dev+alphabm")
cmtk_assert(PROJECT_VERSION_MAJOR EQUAL 4)
cmtk_assert(PROJECT_VERSION_MINOR EQUAL 5)
cmtk_assert(PROJECT_VERSION_PATCH EQUAL 6)
cmtk_assert("'${PROJECT_VERSION_PRE_RELEASE}'" STREQUAL "'dev'")
cmtk_assert("'${PROJECT_VERSION_BUILD_METADATA}'" STREQUAL "'alphabm'")

# cmtk_set_project_semantic_version() X.Y.Z PRE_RELEASE
cmtk_set_project_semantic_version(7.8.9 PRE_RELEASE "beta")
cmtk_assert(PROJECT_VERSION STREQUAL "7.8.9")
cmtk_assert(PROJECT_SEMANTIC_VERSION STREQUAL "7.8.9-beta")
cmtk_assert(PROJECT_VERSION_MAJOR EQUAL 7)
cmtk_assert(PROJECT_VERSION_MINOR EQUAL 8)
cmtk_assert(PROJECT_VERSION_PATCH EQUAL 9)
cmtk_assert("'${PROJECT_VERSION_PRE_RELEASE}'" STREQUAL "'beta'")
cmtk_assert("'${PROJECT_VERSION_BUILD_METADATA}'" STREQUAL "''")

# cmtk_set_project_semantic_version() X.Y.Z BUILD_METADATA
cmtk_set_project_semantic_version(10.11.12 BUILD_METADATA "gammabm")
cmtk_assert(PROJECT_VERSION STREQUAL "10.11.12")
cmtk_assert(PROJECT_SEMANTIC_VERSION STREQUAL "10.11.12+gammabm")
cmtk_assert(PROJECT_VERSION_MAJOR EQUAL 10)
cmtk_assert(PROJECT_VERSION_MINOR EQUAL 11)
cmtk_assert(PROJECT_VERSION_PATCH EQUAL 12)
cmtk_assert("'${PROJECT_VERSION_PRE_RELEASE}'" STREQUAL "''")
cmtk_assert("'${PROJECT_VERSION_BUILD_METADATA}'" STREQUAL "'gammabm'")

project(${PROJECT_NAME}
    VERSION ${PROJECT_VERSION}
    LANGUAGES CXX
)

# cmtk_set_package_component_names() REQUIRED
cmtk_set_package_component_names(
    REQUIRED "main_feature"
)
string(JOIN "," components "${PACKAGE_REQUIRED_COMPONENTS}")
cmtk_assert(components STREQUAL "main_feature")
string(JOIN "," components ${PACKAGE_OPTIONAL_COMPONENTS})
cmtk_assert("'${components}'" STREQUAL "''")
string(JOIN "," components ${PACKAGE_COMPONENTS})
cmtk_assert(components STREQUAL "main_feature")

# cmtk_set_package_component_names() OPTIONAL
cmtk_set_package_component_names(
    OPTIONAL "alpha_feature" "beta_feature"
)
string(JOIN "," components "${PACKAGE_REQUIRED_COMPONENTS}")
cmtk_assert("'${components}'" STREQUAL "''")
string(JOIN "," components ${PACKAGE_OPTIONAL_COMPONENTS})
cmtk_assert(components STREQUAL "alpha_feature,beta_feature")
string(JOIN "," components ${PACKAGE_COMPONENTS})
cmtk_assert(components STREQUAL "alpha_feature,beta_feature")

# cmtk_set_package_component_names() REQUIRED OPTIONAL
cmtk_set_package_component_names(
    REQUIRED "main_feature"
    OPTIONAL "alpha_feature" "beta_feature"
)
string(JOIN "," components "${PACKAGE_REQUIRED_COMPONENTS}")
cmtk_assert(components STREQUAL "main_feature")
string(JOIN "," components ${PACKAGE_OPTIONAL_COMPONENTS})
cmtk_assert(components STREQUAL "alpha_feature,beta_feature")
string(JOIN "," components ${PACKAGE_COMPONENTS})
cmtk_assert(components STREQUAL "main_feature,alpha_feature,beta_feature")

# cmtk_build_component_option()
cmtk_build_component_option(COMPONENT_NAME alpha_feature)
cmtk_assert(DEFINED ${PACKAGE_UPPER_VAR_NAME}_ALPHA_FEATURE_BUILD
    AND ${${PACKAGE_UPPER_VAR_NAME}_ALPHA_FEATURE_BUILD})

# cmtk_add_component_subdirectory_if_built() component_dirname
cmtk_add_component_subdirectory_if_built(main_feature)
cmtk_assert(MAIN_FEATURE_CONFIGURED)

# cmtk_add_component_subdirectory_if_built() component_dirpath COMPONENT_NAME
cmtk_add_component_subdirectory_if_built(component/alpha_feature COMPONENT_NAME alpha_feature)
cmtk_assert(ALPHA_FEATURE_CONFIGURED)
cmtk_add_component_subdirectory_if_built(component/beta_feature COMPONENT_NAME beta_feature)
cmtk_assert(BETA_FEATURE_CONFIGURED)

# cmtk_add_example_subdirectory_if_built()
cmtk_add_example_subdirectory_if_built(example)
cmtk_assert(DEFINED ${PACKAGE_UPPER_VAR_NAME}_${PROJECT_UPPER_VAR_NAME}_BUILD_EXAMPLES
    AND NOT ${${PACKAGE_UPPER_VAR_NAME}_${PROJECT_UPPER_VAR_NAME}_BUILD_EXAMPLES})
set(${PACKAGE_UPPER_VAR_NAME}_${PROJECT_UPPER_VAR_NAME}_BUILD_EXAMPLES ON)
cmtk_add_example_subdirectory_if_built(example)
cmtk_assert(EXAMPLE_CONFIGURED)

# cmtk_add_test_subdirectory_if_built()
cmtk_add_test_subdirectory_if_built(test)
cmtk_assert(DEFINED ${PACKAGE_UPPER_VAR_NAME}_${PROJECT_UPPER_VAR_NAME}_BUILD_TESTS
    AND NOT ${${PACKAGE_UPPER_VAR_NAME}_${PROJECT_UPPER_VAR_NAME}_BUILD_TESTS})
set(${PACKAGE_UPPER_VAR_NAME}_${PROJECT_UPPER_VAR_NAME}_BUILD_TESTS ON)
cmtk_add_test_subdirectory_if_built(test)
cmtk_assert(TEST_CONFIGURED)

# cmtk_configure_files()
cmtk_configure_files(configured_headers
    BASE_DIR
        include
    BINARY_BASE_DIR
        ${CMAKE_CURRENT_BINARY_DIR}/include
    FILES
        include/proj_alpha_lib/tools.hpp.in
)
cmtk_configure_files(configured_sources
    BASE_DIR
        src
    BINARY_BASE_DIR
        ${CMAKE_CURRENT_BINARY_DIR}/src
    FILES
        src/proj_alpha_lib/tools.cpp.in
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
