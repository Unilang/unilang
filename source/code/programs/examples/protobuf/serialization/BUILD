load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("//bazel/rules/protobuf:cpp.bzl", "cpp_proto_object")

package(
    default_visibility = ["//visibility:public"],
)

cpp_proto_object(
    name = "message",
)

cpp_main(
    name = "main",
    deps = [
        ":message_cpp_proto",
        "//code/utilities/formats/serialization:protobuf",
    ],
)
