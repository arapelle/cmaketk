
include(${CMAKE_CURRENT_LIST_DIR}/utility.cmake)

function(cmtk_add_cpp_library_gtest test_name library_target gtest_target)
    # Args:
    set(options "")
    set(params "DEFAULT_WARNING_OPTIONS;DEFAULT_ERROR_OPTIONS;CXX_STANDARD")
    set(lists "HEADERS;SOURCES;LINK_LIBRARIES")
    # Parse args:
    cmake_parse_arguments(PARSE_ARGV 1 "ARG" "${options}" "${params}" "${lists}")
    # Check args:
    cmtk_fatal_ifndef("You must provide a list of test source files." ARG_SOURCES)
    cmtk_set_ifndef(ARG_DEFAULT_WARNING_OPTIONS ON)
    #
    add_executable(${test_name} ${ARG_SOURCES} ${ARG_HEADERS})
    target_link_libraries(${test_name} PRIVATE ${library_target} ${ARG_LINK_LIBRARIES} ${gtest_target})
    if(${ARG_DEFAULT_WARNING_OPTIONS})
        cmtk_target_default_warning_options(${test_name})
    endif()
    if(${ARG_DEFAULT_ERROR_OPTIONS})
        cmtk_target_default_error_options(${test_prog})
    endif()
    if(ARG_CXX_STANDARD)
        target_compile_features(${test_name} PRIVATE cxx_std_${ARG_CXX_STANDARD})
    endif()
    cmtk_copy_runtime_dlls_if_win32(${test_name} RUNTIME_OUTPUT_SUBDIRECTORY ${test_name})
    gtest_discover_tests(${test_name} TEST_PREFIX ${library_target}::)
endfunction()

function(cmtk_add_cpp_library_basic_gtests library_target gtest_target)
    # Args:
    set(options "")
    set(params "DEFAULT_WARNING_OPTIONS;DEFAULT_ERROR_OPTIONS;CXX_STANDARD")
    set(lists "SOURCES;LINK_LIBRARIES")
    # Parse args:
    cmake_parse_arguments(PARSE_ARGV 0 "ARG" "${options}" "${params}" "${lists}")
    # Check args:
    cmtk_fatal_ifndef("You must provide a list of test source files." ARG_SOURCES)
    cmtk_set_ifndef(ARG_DEFAULT_WARNING_OPTIONS ON)
    #
    foreach(filename ${ARG_SOURCES})
        get_filename_component(test_prog ${filename} NAME_WE)
        set(test_prog "${library_target}-${test_prog}")
        add_executable(${test_prog} ${filename})
        target_link_libraries(${test_prog} PRIVATE ${library_target} ${ARG_LINK_LIBRARIES} ${gtest_target})
        if(${ARG_DEFAULT_WARNING_OPTIONS})
            cmtk_target_default_warning_options(${test_prog})
        endif()
        if(${ARG_DEFAULT_ERROR_OPTIONS})
            cmtk_target_default_error_options(${test_prog})
        endif()
        if(ARG_CXX_STANDARD)
            target_compile_features(${test_prog} PRIVATE cxx_std_${ARG_CXX_STANDARD})
        endif()
        cmtk_copy_runtime_dlls_if_win32(${test_prog} RUNTIME_OUTPUT_SUBDIRECTORY ${test_prog})
        gtest_discover_tests(${test_prog} TEST_PREFIX ${library_target}::)
    endforeach()
endfunction()

# EXAMPLES:

function(cmtk_add_cpp_library_example example_name library_target)
    # Args:
    set(options "")
    set(params "DEFAULT_WARNING_OPTIONS;DEFAULT_ERROR_OPTIONS;CXX_STANDARD")
    set(lists "HEADERS;SOURCES;LINK_LIBRARIES")
    # Parse args:
    cmake_parse_arguments(PARSE_ARGV 2 "ARG" "${options}" "${params}" "${lists}")
    # Check args:
    cmtk_fatal_ifndef("You must provide a list of example source files." ARG_SOURCES)
    cmtk_set_ifndef(ARG_DEFAULT_WARNING_OPTIONS ON)
    #
    add_executable(${example_name} ${ARG_SOURCES} ${ARG_HEADERS})
    target_link_libraries(${example_name} PRIVATE ${library_target} ${ARG_LINK_LIBRARIES})
    if(${ARG_DEFAULT_WARNING_OPTIONS})
        cmtk_target_default_warning_options(${example_name})
    endif()
    if(${ARG_DEFAULT_ERROR_OPTIONS})
        cmtk_target_default_error_options(${example_name})
    endif()
    if(ARG_CXX_STANDARD)
        target_compile_features(${example_name} PRIVATE cxx_std_${ARG_CXX_STANDARD})
    endif()
    cmtk_copy_runtime_dlls_if_win32(${example_name} RUNTIME_OUTPUT_SUBDIRECTORY ${example_name})
endfunction()

function(cmtk_add_cpp_library_basic_examples library_target)
    # Args:
    set(options "")
    set(params "DEFAULT_WARNING_OPTIONS;DEFAULT_ERROR_OPTIONS;CXX_STANDARD")
    set(lists "SOURCES;LINK_LIBRARIES")
    # Parse args:
    cmake_parse_arguments(PARSE_ARGV 1 "ARG" "${options}" "${params}" "${lists}")
    # Check args:
    cmtk_fatal_ifndef("You must provide a list of example source files." ARG_SOURCES)
    cmtk_set_ifndef(ARG_DEFAULT_WARNING_OPTIONS ON)
    #
    foreach(filename ${ARG_SOURCES})
        get_filename_component(example_prog ${filename} NAME_WE)
        add_executable(${example_prog} ${filename})
        target_link_libraries(${example_prog} PRIVATE ${library_target} ${ARG_LINK_LIBRARIES})
        if(${ARG_DEFAULT_WARNING_OPTIONS})
            cmtk_target_default_warning_options(${example_prog})
        endif()
        if(${ARG_DEFAULT_ERROR_OPTIONS})
            cmtk_target_default_error_options(${example_prog})
        endif()
        if(ARG_CXX_STANDARD)
            target_compile_features(${example_prog} PRIVATE cxx_std_${ARG_CXX_STANDARD})
        endif()
        cmtk_copy_runtime_dlls_if_win32(${example_prog} RUNTIME_OUTPUT_SUBDIRECTORY ${example_prog})
    endforeach()
endfunction()
