package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "test_enum",
    values = [
        "foo",
        "bar",
        "baz",
    ],
)

cc_binary(
    name = "enum_program",
    srcs = ["test.cc"],
    deps = [
        "//code/programs/transcompilers/enum_cpp/example:test_enum",
        "@pretty_print//:lib",
    ],
)
