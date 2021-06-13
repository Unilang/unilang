package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp(
    name = "dependency_specifications",
    deps = [
        "//code/programs/reflexivity/deps_define/data:dependency_specification",
    ],
)

hcp(
    name = "dependency_specification",
    deps = [
        "//code/programs/reflexivity/deps_define/data:build_definitions",
        "//code/programs/reflexivity/deps_define/data:dependency_location",
        "//code/programs/reflexivity/deps_define/data:patch_file",
        "//code/programs/reflexivity/deps_define/data:patch_settings",
    ],
)

hcp(
    name = "patch_settings",
    deps = [
        "//code/programs/reflexivity/deps_define/data:patch_file",
    ],
)

hcp(
    name = "dependency_specifications_getter",
    deps = [
        "//code/programs/reflexivity/deps_define/data:common_patch_cmds_getter",
        "//code/programs/reflexivity/deps_define/data:dependency_specifications",
    ],
)

hcp(
    name = "common_patch_cmds_getter",
    deps = [
        "//code/programs/reflexivity/deps_define/data:dependency_specifications",
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
