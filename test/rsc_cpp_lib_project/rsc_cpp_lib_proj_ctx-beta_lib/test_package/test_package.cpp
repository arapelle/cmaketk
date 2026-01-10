#include <rsc_cpp_lib_proj_ctx/beta_lib/find_serialized_resource.hpp>
#include <rsc_cpp_lib_proj_ctx/beta_lib/paths.hpp>
#include <rsc_cpp_lib_proj_ctx/beta_lib/rsc/icon.hpp>
#include <rsc_cpp_lib_proj_ctx/beta_lib/get_serialized_resource.hpp>

#include <iostream>

int main()
{
    std::string_view rsc_path = "RSCLIB:/text/tale.txt";
    std::optional<std::span<const std::byte>> rsc_bytes_o =
        rsc_cpp_lib_proj_ctx::beta_lib::find_serialized_resource(rsc_path);
    if (rsc_bytes_o)
        std::cout << "Resource found: size=" << rsc_bytes_o->size() << std::endl;
    else
        std::cout << "Resource not found" << std::endl;
    return EXIT_SUCCESS;
}
