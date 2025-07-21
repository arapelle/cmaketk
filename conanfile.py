import os, re

from conan import ConanFile
from conan.tools.build import check_min_cppstd
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
from conan.tools.files import load, copy, rm

required_conan_version = ">=2.2.0"

class CmaketkRecipe(ConanFile):
    name = "cmaketk"
    package_type = "build-scripts"

    # Optional metadata
    description = "CMake Toolkit providing CMake functions for different kinds of uses (project, lib, exe, tests, ...)."
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
    exports_sources = "LICENSE.md", "CMakeLists.txt", "test/*", "cmake/config/*", "cmake/module/*"

    def set_version(self):
        print("TRACE: set_version")
        cmakelist_content = load(self, os.path.join(self.recipe_folder, "CMakeLists.txt"))
        version_regex = r"""project\([a-z_]+ *VERSION *?([0-9]+\.[0-9]+\.[0-9]+).*"""
        self.version = re.search(version_regex, cmakelist_content).group(1)

    def source(self):
        print("TRACE: source")
        pass

    def layout(self):
        print("TRACE: layout")
        cmake_layout(self)

    def validate(self):
        print("TRACE: validate")
        if not self.conf.get("tools.build:skip_test", default=True):
            check_min_cppstd(self, 20)
    
    def build_requirements(self):
        print("TRACE: build_requirements")
        if not self.conf.get("tools.build:skip_test", default=True):
            self.test_requires("gtest/[^1.14]")

    def generate(self):
        print("TRACE: generate")
        tc = CMakeToolchain(self)
        # https://docs.conan.io/2/tutorial/creating_packages/build_packages.html
        # https://docs.conan.io/2/tutorial/creating_packages/other_types_of_packages/header_only_packages.html
        # https://docs.conan.io/2/reference/commands/create.html
        # conan create . -c tools.build:skip_test=False
        if not self.conf.get("tools.build:skip_test", default=True):
            upper_name = f"{self.name}".upper()
            tc.variables[f"BUILD_{upper_name}_TESTS"] = "TRUE"
        tc.generate()

    def build(self):
        print("TRACE: build")
        cmake = CMake(self)
        cmake.configure()
        if not self.conf.get("tools.build:skip_test", default=True):
            print("DO_TEST !!")
            cmake.build()
            cmake.ctest(cli_args=["--progress", "--output-on-failure"])
        else:
            print("SKIP_TEST !?!")

    def package(self):
        print("TRACE: package")
        copy(self, "LICENSE.md", src=self.source_folder, dst=os.path.join(self.package_folder, "licenses"))
        cmake = CMake(self)
        cmake.install()
        rm(self, "uninstall.cmake", os.path.join(self.package_folder, "lib", "cmake"))

    def package_info(self):
        print("TRACE: package_info")
        self.cpp_info.builddirs = [os.path.join("lib", "cmake", self.name)]
        self.cpp_info.set_property("cmake_find_mode", "none")

#    def package_id(self):
#        print("TRACE: package_id")
#        self.info.clear()
