package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_binary(
    name = "refresh_keygen",
    srcs = ["refresh_keygen.cpp"],
    deps = ["//code/utilities/system/machine_setup:keygen_refresher"],
)

cc_binary(
    name = "provision_machine",
    srcs = ["provision_machine.cpp"],
    deps = ["//code/utilities/system/machine_setup:machine_provisioner"],
)
