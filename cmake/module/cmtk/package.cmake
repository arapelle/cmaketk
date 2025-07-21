include(${CMAKE_CURRENT_LIST_DIR}/utility.cmake)

function(cmtk_install_package package_name)
    include(GNUInstallDirs)
    include(CMakePackageConfigHelpers)
    # Args:
    set(options "")
    set(params "VERSION;VERSION_COMPATIBILITY;INPUT_PACKAGE_CONFIG_FILE;DESTINATION")
    set(lists "")
    # Parse args:
    cmake_parse_arguments(PARSE_ARGV 1 "ARG" "${options}" "${params}" "${lists}")
    # Check and set args:
    fatal_ifndef("INPUT_PACKAGE_CONFIG_FILE is required (e.g. CMake-package-config.cmake.in)" ARG_INPUT_PACKAGE_CONFIG_FILE)
    set_ifndef(ARG_VERSION ${PROJECT_VERSION})
    set_ifndef(ARG_VERSION_COMPATIBILITY SameMajorVersion)
    set_ifndef(ARG_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${package_name}")
    # Create package config file:
    configure_package_config_file(${ARG_INPUT_PACKAGE_CONFIG_FILE}
        "${PROJECT_BINARY_DIR}/${package_name}-config.cmake"
        INSTALL_DESTINATION ${ARG_DESTINATION})
    # Create package version file:
    write_basic_package_version_file("${PROJECT_BINARY_DIR}/${package_name}-config-version.cmake"
        VERSION ${ARG_VERSION}
        COMPATIBILITY ${ARG_VERSION_COMPATIBILITY})
    # Install package files:
    install(FILES
        ${PROJECT_BINARY_DIR}/${package_name}-config.cmake
        ${PROJECT_BINARY_DIR}/${package_name}-config-version.cmake
        DESTINATION ${ARG_DESTINATION})
endfunction()

function(cmtk_install_uninstall_script package_name)
    include(GNUInstallDirs)
    # Args:
    set(options "ALL")
    set(params "FILENAME;DESTINATION;VERSION")
    set(lists "")
    # Parse args:
    cmake_parse_arguments(PARSE_ARGV 1 "ARG" "${options}" "${params}" "${lists}")
    # Check args:
    set_ifndef(ARG_FILENAME "uninstall.cmake")
    set_ifndef(ARG_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${package_name}")
    set_ifndef(ARG_VERSION "${PROJECT_VERSION}")
    set(rel_uninstall_path "${ARG_DESTINATION}/${ARG_FILENAME}")
    #
    set(uninstall_script_code "
        message(STATUS \"Installing: \${CMAKE_INSTALL_PREFIX}/${rel_uninstall_path}\")
        if(DEFINED CMAKE_INSTALL_MANIFEST_FILES)
            set(uninstall_script \${CMAKE_INSTALL_PREFIX}/${rel_uninstall_path})
            list(APPEND CMAKE_INSTALL_MANIFEST_FILES \${uninstall_script})
            set(files \${CMAKE_INSTALL_MANIFEST_FILES})
        ")
    if(ARG_ALL)
        string(APPEND uninstall_script_code "
            set(CMTK_INSTALL_FILES \${files})
            ")
    else()
        string(APPEND uninstall_script_code "
            if(CMTK_INSTALL_FILES)
                list(REMOVE_ITEM files \${CMTK_INSTALL_FILES})
            endif()
            list(APPEND CMTK_INSTALL_FILES \${files})
            ")
    endif()
    string(APPEND uninstall_script_code "
        file(APPEND \${CMAKE_INSTALL_PREFIX}/${rel_uninstall_path}
        \"
        message(STATUS \\\"Uninstall ${package_name} v${ARG_VERSION} ${CMAKE_BUILD_TYPE}\\\")
        foreach(file \${files})
            while(NOT \\\${file} STREQUAL \${CMAKE_INSTALL_PREFIX})
                if(EXISTS \\\${file} OR IS_SYMLINK \\\${file})
                    if(IS_DIRECTORY \\\${file})
                        file(GLOB dir_files \\\${file}/*)
                        list(LENGTH dir_files number_of_files)
                        if(\\\${number_of_files} EQUAL 0)
                          message(STATUS \\\"Removing  dir: \\\${file}\\\")
                          file(REMOVE_RECURSE \\\${file})
                        endif()
                    else()
                        message(STATUS \\\"Removing file: \\\${file}\\\")
                        file(REMOVE \\\${file})
                    endif()
                endif()
                get_filename_component(file \\\${file} DIRECTORY)
            endwhile()
        endforeach()
        \"
        )
    else()
        message(ERROR \"cmake_uninstall.cmake script cannot be created!\")
    endif()
        ")
    install(CODE ${uninstall_script_code})
endfunction()

function(cmtk_clear_install_file_list)
    install(CODE "set(CMTK_INSTALL_FILES \${CMAKE_INSTALL_MANIFEST_FILES})")
endfunction()
