package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "url_parser",
    deps = [
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "@cxx_url",
    ],
)

hcp(
    name = "github_url_getter",
    deps = [
    ],
)

hcp(
    name = "url_identifier",
    deps = [
        "//code/utilities/types/strings/observers/other:lib",
    ],
)
