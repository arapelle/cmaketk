
include(cmtk/cpp_cmake_workflow_test)

set(projects
    "proj_alpha_lib"
    "proj_ctx-beta_lib"
)

foreach(project ${projects})
    cmtk_add_cpp_cmake_workflow_gtests(${project} GTest::gtest_main PACKAGE_TYPE "lib")
endforeach()
