package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "literal_suffix_getter",
    deps = [
        "//code/utilities/linguistics/computer/literals/getter/data:literal_suffix_settings",
        "//code/utilities/linguistics/computer/types/generic:unilang_type_to_language_type_converter",
        "//code/utilities/types/converters:lib",
    ],
)

hcp(
    name = "cpp_literal_suffix_settings",
    deps = [
        "//code/utilities/linguistics/computer/literals/getter/data:literal_suffix_settings",
    ],
)

hcp(
    name = "java_literal_suffix_settings",
    deps = [
        "//code/utilities/linguistics/computer/literals/getter/data:literal_suffix_settings",
    ],
)
