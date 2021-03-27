package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "advent_of_code_input_getter",
    deps = [
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/streams/filestreams/write_all:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/web:lib",
        "//code/utilities/web/automate/browser:browser_creator",
        "//code/utilities/web/automate/browser:default_browser_settings_getter",
        "//code/utilities/web/automate/navigation:browser_navigator",
        "@pybind11",
    ],
)
