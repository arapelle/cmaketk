cmake_minimum_required(VERSION 3.30)

project(cmake_tools)

add_library(${PROJECT_NAME} INTERFACE)
target_sources(${PROJECT_NAME} PUBLIC FILE_SET HEADERS
    BASE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    FILES
        include/cmaketk/cmake_tools/cmake.hpp
        include/cmaketk/cmake_tools/ctest.hpp
        include/cmaketk/cmake_tools/cmake_tools.hpp
)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME} EXPORT ${PACKAGE_NAME}-targets
    FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

add_library(${PACKAGE_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
