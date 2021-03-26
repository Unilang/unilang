load("//bazel/rules/cpp:gtest.bzl", "gtest")

package(
    default_visibility = ["//visibility:public"],
)

gtest(
    name = "nonintrusive",
    deps = [
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/formats/json/overloads:variant_json_converters",
        "@nlohmann_json",
    ],
)
