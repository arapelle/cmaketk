
include(cmtk/cpp_cmake_workflow_test)

set(projects
    "rsc_cpp_lib_proj_ctx-alpha_lib"
    "rsc_cpp_lib_proj_ctx-beta_lib"
    "rsc_cpp_lib_proj_ctx-gamma_lib"
)

foreach(project ${projects})
    cmtk_add_cpp_cmake_workflow_gtests(${project} GTest::gtest_main PACKAGE_TYPE "lib")
endforeach()
