cmake_minimum_required(VERSION 3.30)

include(CMakePrintHelpers)
include(cmtk/rsc_cpp_lib_project)

cmtk_check_in_source_build()
cmtk_set_build_type_ifndef()

cmtk_set_package_name(CONTEXT_NAME "rsc_cpp_lib_proj_ctx" SUBJECT_NAME "gamma_lib")
cmtk_set_package_semantic_version(1.2.3)

cmtk_set_project_name(CONTEXT_NAME "rsc_cpp_lib_proj_ctx" SUBJECT_NAME "gamma_lib")
project(${PACKAGE_NAME}
    VERSION ${PACKAGE_VERSION}
    LANGUAGES CXX
)

cmtk_cxx_standard_option(${PACKAGE_UPPER_VAR_NAME}_CXX_STANDARD MIN 20 MAX 26)
cmtk_shared_or_static_option(${PACKAGE_UPPER_VAR_NAME}_LIBRARY_TYPE SHARED)

# cmtk_add_rsc_cpp_library()
set(headers
    include/rsc_cpp_lib_proj_ctx/gamma_lib/get_serialized_resource.hpp
)
set(sources
    src/rsc_cpp_lib_proj_ctx/gamma_lib/get_serialized_resource.cpp
)
set(resource_files
    ${CMAKE_CURRENT_SOURCE_DIR}/rsc/text/tale.txt                      #    19  o
    ${CMAKE_CURRENT_SOURCE_DIR}/rsc/text/another-tale.txt              #    29  o
    ${CMAKE_CURRENT_SOURCE_DIR}/rsc/text/third\ tale.txt               #    27  o
    ${CMAKE_CURRENT_SOURCE_DIR}/rsc///text///fourth_tale.txt           #    29  o
    ${CMAKE_CURRENT_SOURCE_DIR}/rsc/text///short_message/message.txt   #     6  o
    ${CMAKE_CURRENT_SOURCE_DIR}/rsc/icon.png                           #    ~5 Ko
)
cmtk_add_rsc_cpp_library(${PROJECT_NAME} ${${PROJECT_UPPER_VAR_NAME}_LIBRARY_TYPE}
    PRIVATE_RESOURCE_HEADERS
    PRIVATE_RESOURCE_PATHS_HEADER
    INLINE_CONTEXT_NAMESPACE ${PROJECT_CODE_CONTEXT_NAME}
    NAMESPACE ${PROJECT_CODE_SUBJECT_NAME}
    HEADERS ${headers}
    SOURCES ${sources}
    RESOURCES ${resource_files}
    CXX_STANDARD ${${PACKAGE_UPPER_VAR_NAME}_CXX_STANDARD}
    DEFAULT_WARNING_OPTIONS
    DEFAULT_ERROR_OPTIONS
)

cmtk_add_test_subdirectory_if_built(test)
set(${PACKAGE_UPPER_VAR_NAME}_${PROJECT_UPPER_VAR_NAME}_BUILD_TESTS ON)
cmtk_add_test_subdirectory_if_built(test)

cmtk_install_targets(TARGETS ${PROJECT_NAME} EXPORT ${PACKAGE_NAME}-targets NAMESPACE "${PACKAGE_NAME}::")
cmtk_install_package(${PACKAGE_NAME} INPUT_PACKAGE_CONFIG_FILE package-config.cmake.in)
cmtk_install_uninstall_script(${PACKAGE_NAME} LIB)
