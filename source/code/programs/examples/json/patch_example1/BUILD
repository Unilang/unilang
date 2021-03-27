load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "main",
    deps = [
        "//code/utilities/formats/json/patching:json_patch_builder",
        "@nlohmann_json",
    ],
)
