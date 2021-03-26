package(default_visibility = ["//visibility:public"])

load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("//bazel/rules/unilang:unilang_to_code.bzl", "unilang_to_code")

unilang_to_code("hello_world")

cpp_main(
    "main",
    deps = [
        "//code/examples/unilang/hello_world:hello_world_json_data_getter",
        "//code/utilities/streams/filestreams/read_all:lib",
    ],
)
