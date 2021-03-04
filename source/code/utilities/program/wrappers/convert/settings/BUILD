package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "draw_text_settings",
    deps = [
        "//code/utilities/data_structures/position",
    ],
)

hcp(
    name = "image_settings",
    deps = [
        "//code/utilities/data_structures/dimensions:two_d_dimensions",
    ],
)

hcp(
    name = "image_animated_settings",
    deps = [
        "//code/utilities/data_structures/dimensions:two_d_dimensions",
        "//code/utilities/data_structures/position",
    ],
)
