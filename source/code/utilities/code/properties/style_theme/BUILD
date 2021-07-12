package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "style_lookup_map",
    deps = [
        "//code/utilities/code/properties/style_theme",
        "//code/utilities/data_structures/graphics/objects/label/style:label_styles",
    ],
)

hcp(
    name = "style_lookup_map_getter",
    deps = [
        "//code/utilities/code/properties/style_theme:style_lookup_map",
        "//code/utilities/data_structures/graphics/objects/label/style:default_label_styles",
    ],
)

hcp(
    name = "style_theme",
    deps = [
        "//code/utilities/data_structures/graphics/objects/label/style:label_styles",
    ],
)
