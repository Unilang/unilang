package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "bazel_version_info",
    deps = [
    ],
)

hcp(
    name = "bazel_version_info_getter",
    deps = [
        "//code/programs/reflexivity/bazel_wrapper/data:bazel_version_info",
    ],
)

hcp(
    name = "bazel_wrapper_refresh_settings",
    deps = [
        "//code/programs/reflexivity/bazel_wrapper/data:bazel_version_info",
    ],
)

hcp(
    name = "bazel_wrapper_refresh_settings_getter",
    deps = [
        ":bazel_version_info_getter",
        ":bazel_wrapper_refresh_settings",
    ],
)
