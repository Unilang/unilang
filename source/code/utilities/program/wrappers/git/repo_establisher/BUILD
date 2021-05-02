package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "repo_location",
    deps = [],
)

hcp(
    name = "default_repo_location_getter",
    deps = [
        "//code/utilities/program/wrappers/git/repo_establisher:repo_location",
    ],
)

hcp(
    name = "repo_establisher",
    deps = [
        "//code/utilities/filesystem/files/moving:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/git:lib",
        "//code/utilities/program/wrappers/git/repo_establisher:established_repo",
        "//code/utilities/program/wrappers/git/repo_establisher:repo_location",
        "//code/utilities/random:lib",
        "//code/utilities/random/files:random_files",
        "//code/utilities/time/profile:function_profiler",
    ],
)

hcp(
    name = "established_repo",
    deps = [],
)
