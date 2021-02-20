package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "storage_strs",
    deps = [
    ],
)

hcp(
    name = "language_storage_getter",
    deps = [
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/linguistics/computer/keywords/storage:storage_strs",
        "//code/utilities/types/map:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
    ],
)

hcp(
    name = "storage_keyword_getter",
    deps = [
        "//code/utilities/code:storage_specifier",
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/linguistics/computer/keywords/storage:language_storage_getter",
        "//code/utilities/linguistics/computer/keywords/storage:storage_strs",
        "//code/utilities/types/map:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
    ],
)
