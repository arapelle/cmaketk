cmake_minimum_required(VERSION 3.30)

set(module_root_dir "cmake_module")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/${module_root_dir}")

#-- Package cmaketk ------------------------------------------------------------

set(PACKAGE_NAME cmaketk)
set(PACKAGE_VERSION 0.1.0) # dev

project(${PACKAGE_NAME} VERSION ${PACKAGE_VERSION})
include(GNUInstallDirs)
set(PACKAGE_DIR "lib/cmake/${PACKAGE_NAME}")

# module cmtk
add_subdirectory(${module_root_dir})

# test
option(CMAKETK_BUILD_TESTS "Build cmaketk tests." OFF)
if(CMAKETK_BUILD_TESTS)
    include(CTest)
    if(BUILD_TESTING)
        add_subdirectory(test)
    endif()
endif()

#-- Install Package cmaketk ----------------------------------------------------

include(CMakePackageConfigHelpers)

configure_package_config_file("cmake/config/package-config.cmake.in"
    "${PROJECT_BINARY_DIR}/${PACKAGE_NAME}-config.cmake"
    INSTALL_DESTINATION ${PACKAGE_DIR}
)
write_basic_package_version_file("${PROJECT_BINARY_DIR}/${PACKAGE_NAME}-config-version.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)
install(FILES
    ${PROJECT_BINARY_DIR}/${PACKAGE_NAME}-config.cmake
    ${PROJECT_BINARY_DIR}/${PACKAGE_NAME}-config-version.cmake
    DESTINATION ${PACKAGE_DIR}
)

include(cmtk/project)
cmtk_install_uninstall_script(${PACKAGE_NAME} LIB)
