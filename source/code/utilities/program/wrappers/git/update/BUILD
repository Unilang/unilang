package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "git_update_settings",
    deps = [],
)

hcp(
    name = "git_updater",
    deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/git:branch_switcher",
        "//code/utilities/program/wrappers/git:git_upstream_pusher",
        "//code/utilities/program/wrappers/git/update:git_update_settings",
    ],
)
