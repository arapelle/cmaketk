
include(cmtk/cpp_cmake_workflow_test)

set(projects
    "cpp_exe_proj_ctx-alpha_exe"
)

foreach(project ${projects})
    cmtk_add_cpp_cmake_workflow_gtests(${project} GTest::gtest_main PACKAGE_TYPE "bin")
endforeach()
