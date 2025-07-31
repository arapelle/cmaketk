cmake_minimum_required(VERSION 3.25)

set(module_root_dir "cmake/module")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/${module_root_dir}")

#-- Project -------------------------------------------------------------------

project(cmaketk VERSION 0.1.0) # dev

include(cmtk/project)

cmtk_add_test_subdirectory_if_build(test)

#-- Package -------------------------------------------------------------------

include(cmtk/package)

set(package_dir "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")

# Install scripts
set(component_files
    ${module_root_dir}/cmtk/utility.cmake
    ${module_root_dir}/cmtk/project.cmake
    ${module_root_dir}/cmtk/library_project.cmake
    ${module_root_dir}/cmtk/package.cmake
)

install(FILES
    ${component_files}
    DESTINATION "${package_dir}/component"
)
# Install scripts

# Install package
cmtk_install_package(${PROJECT_NAME}
    INPUT_PACKAGE_CONFIG_FILE "cmake/config/package-config.cmake.in"
    DESTINATION "${package_dir}"
)
cmtk_install_uninstall_script(${PROJECT_NAME}
    DESTINATION "${package_dir}"
)
# End install package
