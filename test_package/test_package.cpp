#include <iostream>
#include <cmaketk/cmake_tools/cmake_tools.hpp>

int main(int argc, char** argv)
{
    std::cout << "TESTING " << argv[0] << std::endl;
    cmake_tools::cmake cmake("");
    cmaketk::cmake_tools::ctest ctest("");
    std::cout << "TEST PACKAGE SUCCESS " << std::endl;
    return EXIT_SUCCESS;
}
