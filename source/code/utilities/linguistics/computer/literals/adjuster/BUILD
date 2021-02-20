package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "literal_adjuster",
    deps = [
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/linguistics/computer/literals/getter:cpp_literal_suffix_settings",
        "//code/utilities/linguistics/computer/literals/getter:java_literal_suffix_settings",
        "//code/utilities/linguistics/computer/literals/getter:literal_suffix_getter",
        "//code/utilities/linguistics/computer/literals/getter/data:floating_point_literal_settings",
        "//code/utilities/linguistics/computer/literals/getter/data:literal_suffix_settings",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/stripping:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)
