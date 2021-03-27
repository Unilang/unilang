package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/programs/repo_tools/network_used/program_options:lib",
        "//code/programs/repo_tools/network_used/settings",
        "//code/programs/repo_tools/network_used/settings:settings_getter",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/processes:lib",
        "//code/utilities/program/wrappers/git/repo_establisher",
        "//code/utilities/program/wrappers/tshark:tshark_spawner",
    ],
)

distributable_cpp_main(
    name = "network_used",
    depends = [
    ],
    description = "find out how the build uses the network",
    deps = [
        "//code/programs/repo_tools/network_used:task_executer",
        "//code/programs/repo_tools/network_used/program_options:lib",
    ],
)
