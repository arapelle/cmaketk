#include <rsc_cpp_lib_proj_ctx/alpha_lib/find_serialized_resource.hpp>
#include <rsc_cpp_lib_proj_ctx/alpha_lib/paths.hpp>
#include <rsc_cpp_lib_proj_ctx/alpha_lib/icon.hpp>
#include <rsc_cpp_lib_proj_ctx/alpha_lib/text/tale.hpp>
#include <rsc_cpp_lib_proj_ctx/alpha_lib/text/another_tale.hpp>
#include <rsc_cpp_lib_proj_ctx/alpha_lib/text/third_tale.hpp>
#include <rsc_cpp_lib_proj_ctx/alpha_lib/text/fourth_tale.hpp>
#include <rsc_cpp_lib_proj_ctx/alpha_lib/text/short_message/message.hpp>
#include <rsc_cpp_lib_proj_ctx/alpha_lib/get_serialized_resource.hpp>

#include <gtest/gtest.h>

TEST(unit_tests, resource_icon__path_and_size__ok)
{
    ASSERT_EQ(alpha_lib::icon_path, "RSCLIB:/icon.png");
    ASSERT_EQ(rsc_cpp_lib_proj_ctx::alpha_lib::icon().size(), 5465);
}

TEST(unit_tests, resource_tale__path_and_size__ok)
{
    ASSERT_EQ(rsc_cpp_lib_proj_ctx::alpha_lib::text::tale_path, "RSCLIB:/text/tale.txt");
    ASSERT_EQ(rsc_cpp_lib_proj_ctx::alpha_lib::text::tale().size(), 19);
}

TEST(unit_tests, resource_message__path_and_size__ok)
{
    ASSERT_EQ(rsc_cpp_lib_proj_ctx::alpha_lib::text::short_message::message_path, "RSCLIB:/text/short_message/message.txt");
    ASSERT_EQ(rsc_cpp_lib_proj_ctx::alpha_lib::text::short_message::message().size(), 6);
}

TEST(unit_tests, find_serialized_resource__tale__found)
{
    std::string_view rsc_path = "RSCLIB:/text/tale.txt";
    std::optional<std::span<const std::byte>> rsc_bytes_o =
        rsc_cpp_lib_proj_ctx::alpha_lib::find_serialized_resource(rsc_path);
    ASSERT_TRUE(static_cast<bool>(rsc_bytes_o));
    ASSERT_EQ(rsc_bytes_o->data(), rsc_cpp_lib_proj_ctx::alpha_lib::text::tale().data());
    ASSERT_EQ(rsc_bytes_o->size(), rsc_cpp_lib_proj_ctx::alpha_lib::text::tale().size());
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes_o->data()), rsc_bytes_o->size());
    ASSERT_EQ(content, "Once upon a time...");
}

TEST(unit_tests, find_serialized_resource__another_tale__found)
{
    std::string_view rsc_path = "RSCLIB:/text/another-tale.txt";
    std::optional rsc_bytes_o = rsc_cpp_lib_proj_ctx::alpha_lib::find_serialized_resource(rsc_path);
    ASSERT_TRUE(static_cast<bool>(rsc_bytes_o));
    ASSERT_EQ(rsc_bytes_o->data(), rsc_cpp_lib_proj_ctx::alpha_lib::text::another_tale().data());
    ASSERT_EQ(rsc_bytes_o->size(), 29);
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes_o->data()), rsc_bytes_o->size());
    ASSERT_EQ(content, "Once upon a time, a knight...");
}

TEST(unit_tests, find_serialized_resource__third_tale__found)
{
    std::string_view rsc_path = "RSCLIB:/text/third tale.txt";
    std::optional rsc_bytes_o = rsc_cpp_lib_proj_ctx::alpha_lib::find_serialized_resource(rsc_path);
    ASSERT_TRUE(static_cast<bool>(rsc_bytes_o));
    ASSERT_EQ(rsc_bytes_o->data(), rsc_cpp_lib_proj_ctx::alpha_lib::text::third_tale().data());
    ASSERT_EQ(rsc_bytes_o->size(), 27);
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes_o->data()), rsc_bytes_o->size());
    ASSERT_EQ(content, "Once upon a time, a frog...");
}

TEST(unit_tests, find_serialized_resource__fourth_tale__found)
{
    std::string_view rsc_path = "RSCLIB:/text/fourth_tale.txt";
    std::optional rsc_bytes_o = rsc_cpp_lib_proj_ctx::alpha_lib::find_serialized_resource(rsc_path);
    ASSERT_TRUE(static_cast<bool>(rsc_bytes_o));
    ASSERT_EQ(rsc_bytes_o->data(), rsc_cpp_lib_proj_ctx::alpha_lib::text::fourth_tale().data());
    ASSERT_EQ(rsc_bytes_o->size(), 29);
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes_o->data()), rsc_bytes_o->size());
    ASSERT_EQ(content, "Once upon a time, a dragon...");
}

TEST(unit_tests, find_serialized_resource__message__found)
{
    std::string_view rsc_path = "RSCLIB:/text/short_message/message.txt";
    std::optional rsc_bytes_o = rsc_cpp_lib_proj_ctx::alpha_lib::find_serialized_resource(rsc_path);
    ASSERT_TRUE(static_cast<bool>(rsc_bytes_o));
    ASSERT_EQ(rsc_bytes_o->data(), rsc_cpp_lib_proj_ctx::alpha_lib::text::short_message::message().data());
    ASSERT_EQ(rsc_bytes_o->size(), 6);
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes_o->data()), rsc_bytes_o->size());
    ASSERT_EQ(content, "coucou");
}

TEST(unit_tests, find_serialized_resource__trap__not_found)
{
    std::string_view rsc_path = "RSCLIB:/trap.txt";
    std::optional rsc_bytes_o = rsc_cpp_lib_proj_ctx::alpha_lib::find_serialized_resource(rsc_path);
    ASSERT_FALSE(static_cast<bool>(rsc_bytes_o));
}

TEST(unit_tests, get_serialized_resource__tale__found)
{
    std::string_view rsc_path = "RSCLIB:/text/tale.txt";
    std::span<const std::byte> rsc_bytes =
        rsc_cpp_lib_proj_ctx::alpha_lib::get_serialized_resource(rsc_path);
    ASSERT_EQ(rsc_bytes.data(), rsc_cpp_lib_proj_ctx::alpha_lib::text::tale().data());
    ASSERT_EQ(rsc_bytes.size(), rsc_cpp_lib_proj_ctx::alpha_lib::text::tale().size());
    std::string_view content(reinterpret_cast<const char*>(rsc_bytes.data()), rsc_bytes.size());
    ASSERT_EQ(content, "Once upon a time...");
}

TEST(unit_tests, get_serialized_resource__trap__not_found)
{
    std::string_view rsc_path = "RSCLIB:/trap.txt";
    ASSERT_THROW(rsc_cpp_lib_proj_ctx::alpha_lib::get_serialized_resource(rsc_path), std::runtime_error);
}
