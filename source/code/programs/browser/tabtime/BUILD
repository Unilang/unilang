package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/rules/data:package_binaries.bzl", "package_binaries")
load("//bazel/rules/data:distributable_data.bzl", "distributable_data")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

#build main and deploy stuff
cc_binary(
    name = "tabtime",
    srcs = ["tabtime.cpp"],
    deps = [
        "//code/programs/browser/tabtime:tabtime_runner",
    ],
)

hcp(
    name = "tabtime_runner",
    deps = [
        "//code/utilities/program/call:lib",
    ],
)
