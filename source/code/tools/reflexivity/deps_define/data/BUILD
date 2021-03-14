package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp(
    name = "dependency_specifications",
    deps = [
        "//code/tools/reflexivity/deps_define/data:dependency_specification",
    ],
)

hcp(
    name = "dependency_specification",
    deps = [
        "//code/tools/reflexivity/deps_define/data:build_definitions",
        "//code/tools/reflexivity/deps_define/data:dependency_location",
        "//code/tools/reflexivity/deps_define/data:patch_file",
    ],
)

hcp(
    name = "dependency_specifications_getter",
    deps = [
        "//code/tools/reflexivity/deps_define/data:common_patch_cmds_getter",
        "//code/tools/reflexivity/deps_define/data:dependency_specifications",
    ],
)

hcp(
    name = "common_patch_cmds_getter",
    deps = [
        "//code/tools/reflexivity/deps_define/data:dependency_specifications",
    ],
)

hcp(
    name = "dependency_location",
    deps = [
    ],
)

hcp(
    name = "build_definitions",
    deps = [
    ],
)

hcp(
    name = "patch_file",
    deps = [
    ],
)
