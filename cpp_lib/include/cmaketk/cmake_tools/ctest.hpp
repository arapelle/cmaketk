#pragma once

#include <filesystem>
#include <format>

inline namespace cmaketk
{
namespace cmake_tools
{

class ctest
{
public:
    static constexpr std::string_view default_extra_options = "--progress --output-on-failure --stop-on-failure";

public:
    explicit ctest(std::filesystem::path ctest_path);

    [[nodiscard]] int test(const std::filesystem::path& build_dpath,
                           std::string_view extra_options = default_extra_options) const;

private:
    std::filesystem::path ctest_path_;
};

inline ctest::ctest(std::filesystem::path ctest_path)
    : ctest_path_(std::move(ctest_path))
{
}

inline int ctest::test(const std::filesystem::path& build_dpath, std::string_view extra_options) const
{
    constexpr std::string_view command_fmt = R"({} {} --test-dir {})";
    const std::string command = std::format(command_fmt,
                                            ctest_path_.string(),
                                            extra_options,
                                            build_dpath.string());
    if (!std::filesystem::is_directory(build_dpath))
        throw std::invalid_argument(std::format("The following path is not a directory or does not exist: {}",
                                                build_dpath.string()));
    return system(command.c_str());
}

}
}
