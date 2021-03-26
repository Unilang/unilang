load("//bazel/rules/capnproto:capnp_to_intermediate.bzl", "capnp_to_intermediate")
load("//bazel/rules/capnproto:intermediate_to_cpp.bzl", "intermediate_to_cpp")
load("//bazel/rules/capnproto:capnp_to_cpp_object.bzl", "capnp_to_cpp_object")

package(
    default_visibility = ["//visibility:public"],
)

capnp_to_cpp_object(name = "example")
