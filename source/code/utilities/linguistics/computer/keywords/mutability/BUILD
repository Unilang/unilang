package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "mutability_strs",
    deps = [
    ],
)

hcp(
    name = "language_mutability_getter",
    deps = [
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/linguistics/computer/keywords/mutability:mutability_strs",
        "//code/utilities/types/map:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
    ],
)

hcp(
    name = "mutability_keyword_getter",
    deps = [
        "//code/utilities/code:mutability",
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/linguistics/computer/keywords/mutability:language_mutability_getter",
        "//code/utilities/linguistics/computer/keywords/mutability:mutability_strs",
        "//code/utilities/types/map:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
    ],
)
