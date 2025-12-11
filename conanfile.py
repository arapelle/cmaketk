import os, re

from conan import ConanFile
from conan.tools.build import check_min_cppstd
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
from conan.tools.files import load, copy, rm, rmdir

required_conan_version = ">=2.2.0"

class CmaketkRecipe(ConanFile):
    name = "cmaketk"
    package_type = "build-scripts"

    # Optional metadata
    description = "A CMake ToolKit providing helping CMake functions to manage CMake projects easily."
    url = "https://github.com/arapelle/cmaketk"
    homepage = "https://github.com/arapelle/cmaketk"
    topics = ("CMake", "CMake tools")
    license = "MIT"
    author = "Aymeric Pellé"

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {}
    default_options = {}

    # Build
    win_bash = os.environ.get('MSYSTEM', None) is not None
    no_copy_source = True

    # Sources
    exports_sources = "LICENSE", "CMakeLists.txt", "test/*", "cmake/config/*", "cmake/module/*"

    def set_version(self):
        cmakelist_content = load(self, os.path.join(self.recipe_folder, "CMakeLists.txt"))
        version_regex = r"""set\( *PACKAGE_VERSION *?([0-9]+\.[0-9]+\.[0-9]+).*"""
        self.version = re.search(version_regex, cmakelist_content).group(1)

    def layout(self):
        cmake_layout(self)
    
    def build_requirements(self):
        if not self.conf.get("tools.build:skip_test", default=True):
            self.test_requires("gtest/[^1.14]")

    def generate(self):
        tc = CMakeToolchain(self)
        if not self.conf.get("tools.build:skip_test", default=True):
            tc.variables["CMTK_BUILD_TESTS"] = "TRUE"
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        if not self.conf.get("tools.build:skip_test", default=True):
            cmake.build()
            cmake.ctest(cli_args=["--progress", "--output-on-failure", "--parallel 1"])

    def package(self):
        copy(self, "LICENSE", src=self.source_folder, dst=os.path.join(self.package_folder, "licenses"))
        cmake = CMake(self)
        cmake.install()
        rm(self, "uninstall.cmake", os.path.join(self.package_folder, "lib", "cmake", self.name))

    def package_info(self):
        self.cpp_info.builddirs = [os.path.join("lib", "cmake", self.name)]
        self.cpp_info.set_property("cmake_find_mode", "none")

    def package_id(self):
        self.info.clear()
