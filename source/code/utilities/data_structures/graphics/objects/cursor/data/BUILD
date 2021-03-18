package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "cursor",
    deps = [
        "//code/utilities/data_structures/shapes/rectangle:positioned_rectangle_settings",
    ],
)

hcp(
    name = "label_cursor",
    deps = [
        "//code/utilities/data_structures/graphics/objects/cursor/data:cursor",
    ],
)

hcp(
    name = "label_cursor_selection",
    deps = [
        "//code/utilities/data_structures/graphics/objects/cursor/data:label_cursor",
        "//code/utilities/data_structures/position",
    ],
)

hcp(
    name = "cursor_ability",
    deps = [
    ],
)

hcp(
    name = "default_cursor_ability",
    deps = [
        "//code/utilities/data_structures/graphics/objects/cursor/data:cursor_ability",
    ],
)

hcp(
    name = "controlled_label_cursor_selections",
    deps = [
        "//code/utilities/data_structures/graphics/objects/cursor/data:cursor_ability",
        "//code/utilities/data_structures/graphics/objects/cursor/data:label_cursor_selection",
    ],
)
