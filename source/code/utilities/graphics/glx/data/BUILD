package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "glx_data",
    deps = [
        "//code/utilities/graphics/x11/data:main_x11_state",
        "@system//:GL",
        "@system//:GL_hdrs",
        "@system//:KHR_hdrs",
    ],
)
