install(FILES
    cmtk/utility.cmake
    cmtk/project.cmake
    cmtk/cpp_project.cmake
    cmtk/cpp_lib_project.cmake
    cmtk/cpp_lib_test.cmake
    cmtk/cpp_lib_example.cmake
    cmtk/cpp_exe_project.cmake
    cmtk/logging.cmake
    cmtk/rsc_cpp_lib_project.cmake
    cmtk/cpp_cmake_workflow_test.cmake
    DESTINATION "${PACKAGE_DIR}/component"
)
install(FILES
    cmtk/._script/cmtk_generate_ftoba_cpp.cmake
    cmtk/._script/cmtk_generate_rsc_hcpp.cmake
    cmtk/._script/cmtk_generate_rsc_lib_hcpp.cmake
    DESTINATION "${PACKAGE_DIR}/component/._script/"
)
