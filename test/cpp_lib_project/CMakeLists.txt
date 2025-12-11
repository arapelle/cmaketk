
include(cmtk/cpp_cmake_workflow_test)

set(projects
    "cpp_lib_proj_ctx-alpha_lib"
)

foreach(project ${projects})
    cmtk_add_cpp_cmake_workflow_gtests(${project} GTest::gtest_main PACKAGE_TYPE "lib")
endforeach()
