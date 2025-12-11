#pragma once

#include <algorithm>
#include <filesystem>
#include <format>

inline namespace cmaketk
{
namespace cmake_tools
{

class cmake
{
private:
    std::filesystem::path cmake_path_;

public:
    explicit cmake(std::filesystem::path cmake_path, bool from_pipe_list_to_cmake_list = true);

    [[nodiscard]] int configure(const std::filesystem::path& source_dpath,
                                const std::filesystem::path& build_dpath,
                                const std::filesystem::path& cmake_module_path = "",
                                const std::filesystem::path& cmake_prefix_path = "",
                                const std::filesystem::path& install_dpath = "",
                                std::string_view extra_options = "",
                                bool remove_build_path_before = true,
                                bool remove_install_path_before = true) const;
    [[nodiscard]] int build(const std::filesystem::path& build_dpath) const;
    [[nodiscard]] int install(const std::filesystem::path& build_dpath) const;
    [[nodiscard]] int uninstall(const std::filesystem::path& uninstall_script_fpath) const;

private:
    [[nodiscard]] std::string pipe_list_to_cmake_list_(std::string str) const;

private:
    bool from_pipe_list_to_cmake_list_;
};

inline cmake::cmake(std::filesystem::path cmake_path, bool from_pipe_list_to_cmake_list)
    : cmake_path_(std::move(cmake_path)), from_pipe_list_to_cmake_list_(from_pipe_list_to_cmake_list)
{
}

inline int cmake::configure(const std::filesystem::path& source_dpath,
                            const std::filesystem::path& build_dpath,
                            const std::filesystem::path& cmake_module_path,
                            const std::filesystem::path& cmake_prefix_path,
                            const std::filesystem::path& install_dpath,
                            std::string_view extra_options,
                            bool remove_build_path_before,
                            bool remove_install_path_before) const
{
    if (remove_build_path_before && std::filesystem::is_directory(build_dpath))
        std::filesystem::remove_all(build_dpath);
    if (remove_install_path_before && std::filesystem::is_directory(install_dpath))
        std::filesystem::remove_all(install_dpath);

    std::string cmake_module_path_opt;
    std::string cmake_prefix_path_opt;
    std::string install_prefix_opt;
    if (!cmake_module_path.empty())
        cmake_module_path_opt = std::format(R"(-DCMAKE_MODULE_PATH="{}")",
                                            pipe_list_to_cmake_list_(cmake_module_path.generic_string()));
    if (!cmake_prefix_path.empty())
        cmake_prefix_path_opt = std::format(R"(-DCMAKE_PREFIX_PATH="{}")",
                                            pipe_list_to_cmake_list_(cmake_prefix_path.string()));
    if (!install_dpath.empty())
        install_prefix_opt = std::format(R"(-DCMAKE_INSTALL_PREFIX="{}")", install_dpath.string());
    constexpr std::string_view command_fmt =
        R"({} {} {} {} {} -S {} -B {})";
    const std::string command = std::format(command_fmt,
                                            cmake_path_.string(),
                                            cmake_module_path_opt,
                                            cmake_prefix_path_opt,
                                            install_prefix_opt,
                                            extra_options,
                                            source_dpath.string(),
                                            build_dpath.string());
    if (!std::filesystem::is_directory(source_dpath))
        throw std::invalid_argument(std::format("The following path is not a directory or does not exist: {}",
                                                source_dpath.string()));
    std::filesystem::create_directories(build_dpath);
    int res = system(command.c_str());
    if (res == 0 && !install_dpath.empty())
    {
        std::filesystem::create_directories(install_dpath / "bin");
        std::filesystem::create_directories(install_dpath / "include");
        std::filesystem::create_directories(install_dpath / "lib");
    }
    return res;
}

inline int cmake::build(const std::filesystem::path& build_dpath) const
{
    constexpr std::string_view command_fmt = R"({} --build   {})";
    const std::string command = std::format(command_fmt,
                                            cmake_path_.string(),
                                            build_dpath.string());
    if (!std::filesystem::is_directory(build_dpath))
        throw std::invalid_argument(std::format("The following path is not a directory or does not exist: {}",
                                                build_dpath.string()));
    return system(command.c_str());
}

inline int cmake::install(const std::filesystem::path& build_dpath) const
{
    constexpr std::string_view command_fmt = R"({} --install {})";
    const std::string command = std::format(command_fmt,
                                            cmake_path_.string(),
                                            build_dpath.string());
    if (!std::filesystem::is_directory(build_dpath))
        throw std::invalid_argument(std::format("The following path is not a directory or does not exist: {}",
                                                build_dpath.string()));
    return system(command.c_str());
}

inline int cmake::uninstall(const std::filesystem::path& uninstall_script_fpath) const
{
    constexpr std::string_view command_fmt = R"({} -P {})";
    const std::string command = std::format(command_fmt,
                                            cmake_path_.string(),
                                            uninstall_script_fpath.string());
    if (!std::filesystem::is_regular_file(uninstall_script_fpath))
        throw std::invalid_argument(std::format("The following path is not a file path or does not exist: {}",
                                                uninstall_script_fpath.string()));
    return system(command.c_str());
}

inline std::string cmake::pipe_list_to_cmake_list_(std::string str) const
{
    if (from_pipe_list_to_cmake_list_)
        std::ranges::replace(str, '|', ';');
    return str;
}

}
}
