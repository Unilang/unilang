load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "main",
    deps = [
        "//code/utilities/formats/csv:csv_extractor",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/call:lib",
    ],
)
