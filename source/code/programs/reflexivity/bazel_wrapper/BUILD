package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "bazel_wrapper_refresher",
    deps = [
        "//code/programs/reflexivity/bazel_wrapper/data:bazel_wrapper_refresh_settings_getter",
        "//code/programs/reflexivity/comment:generated_comment_getter",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)
