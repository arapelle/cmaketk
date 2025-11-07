#include <rsc_cpp_lib_proj_ctx/gamma_lib/find_serialized_resource.hpp>
#if __has_include(<rsc_cpp_lib_proj_ctx/gamma_lib/paths.hpp>)
#error "It should be inaccessible."
#endif
#if __has_include(<rsc_cpp_lib_proj_ctx/gamma_lib/rsc/icon.hpp>)
#error "It should be inaccessible."
#endif
#include <rsc_cpp_lib_proj_ctx/gamma_lib/get_serialized_resource.hpp>

#include <gtest/gtest.h>

TEST(unit_tests, find_serialized_resource__tale__found)
{
    std::string_view rsc_path = "rsc/text/tale.txt";
    std::optional<std::span<const std::byte>> rsc_bytes_o =
        rsc_cpp_lib_proj_ctx::gamma_lib::find_serialized_resource(rsc_path);
    ASSERT_TRUE(static_cast<bool>(rsc_bytes_o));
    ASSERT_EQ(rsc_bytes_o->size(), 19);
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes_o->data()), rsc_bytes_o->size());
    ASSERT_EQ(content, "Once upon a time...");
}

TEST(unit_tests, find_serialized_resource__another_tale__found)
{
    std::string_view rsc_path = "rsc/text/another-tale.txt";
    std::optional rsc_bytes_o = rsc_cpp_lib_proj_ctx::gamma_lib::find_serialized_resource(rsc_path);
    ASSERT_TRUE(static_cast<bool>(rsc_bytes_o));
    ASSERT_EQ(rsc_bytes_o->size(), 29);
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes_o->data()), rsc_bytes_o->size());
    ASSERT_EQ(content, "Once upon a time, a knight...");
}

TEST(unit_tests, find_serialized_resource__third_tale__found)
{
    std::string_view rsc_path = "rsc/text/third tale.txt";
    std::optional rsc_bytes_o = rsc_cpp_lib_proj_ctx::gamma_lib::find_serialized_resource(rsc_path);
    ASSERT_TRUE(static_cast<bool>(rsc_bytes_o));
    ASSERT_EQ(rsc_bytes_o->size(), 27);
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes_o->data()), rsc_bytes_o->size());
    ASSERT_EQ(content, "Once upon a time, a frog...");
}

TEST(unit_tests, find_serialized_resource__fourth_tale__found)
{
    std::string_view rsc_path = "rsc/text/fourth_tale.txt";
    std::optional rsc_bytes_o = rsc_cpp_lib_proj_ctx::gamma_lib::find_serialized_resource(rsc_path);
    ASSERT_TRUE(static_cast<bool>(rsc_bytes_o));
    ASSERT_EQ(rsc_bytes_o->size(), 29);
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes_o->data()), rsc_bytes_o->size());
    ASSERT_EQ(content, "Once upon a time, a dragon...");
}

TEST(unit_tests, find_serialized_resource__message__found)
{
    std::string_view rsc_path = "rsc/text/short_message/message.txt";
    std::optional rsc_bytes_o = rsc_cpp_lib_proj_ctx::gamma_lib::find_serialized_resource(rsc_path);
    ASSERT_TRUE(static_cast<bool>(rsc_bytes_o));
    ASSERT_EQ(rsc_bytes_o->size(), 6);
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes_o->data()), rsc_bytes_o->size());
    ASSERT_EQ(content, "coucou");
}

TEST(unit_tests, find_serialized_resource__trap__not_found)
{
    std::string_view rsc_path = "rsc/trap.txt";
    std::optional rsc_bytes_o = rsc_cpp_lib_proj_ctx::gamma_lib::find_serialized_resource(rsc_path);
    ASSERT_FALSE(static_cast<bool>(rsc_bytes_o));
}

TEST(unit_tests, get_serialized_resource__tale__found)
{
    std::string_view rsc_path = "rsc/text/tale.txt";
    std::span<const std::byte> rsc_bytes =
        rsc_cpp_lib_proj_ctx::gamma_lib::get_serialized_resource(rsc_path);
    ASSERT_EQ(rsc_bytes.size(), 19);
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes.data()), rsc_bytes.size());
    ASSERT_EQ(content, "Once upon a time...");
}

TEST(unit_tests, get_serialized_resource__trap__not_found)
{
    std::string_view rsc_path = "rsc/trap.txt";
    ASSERT_THROW(rsc_cpp_lib_proj_ctx::gamma_lib::get_serialized_resource(rsc_path), std::runtime_error);
}
