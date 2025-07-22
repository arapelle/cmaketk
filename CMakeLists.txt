cmake_minimum_required(VERSION 3.30)

set(module_root_dir "cmake/module")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/${module_root_dir}")

#-- Project -------------------------------------------------------------------

project(cmaketk VERSION 0.1.0) # dev

add_subdirectory(test)

#-- Package -------------------------------------------------------------------

set(package_dir "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")

# Install scripts
set(component_files
    ${module_root_dir}/cmtk/utility.cmake
)

install(FILES
    ${component_files}
    DESTINATION "${package_dir}/component"
)
# Install scripts

# Install package
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

configure_package_config_file("cmake/config/package-config.cmake.in"
    "${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
    INSTALL_DESTINATION ${package_dir}
)
write_basic_package_version_file("${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)
install(FILES
    ${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
    ${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
    DESTINATION ${package_dir}
)
# End install package
