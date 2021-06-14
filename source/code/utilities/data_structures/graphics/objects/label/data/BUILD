package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_pos.bzl", "hcp_pos")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "label_user_state",
    deps = [
    ],
)

hcp(
    name = "label_settings",
    deps = [
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/graphics/objects/cursor/data:controlled_label_cursor_selections",
        "//code/utilities/data_structures/graphics/objects/cursor/data:label_cursor",
        "//code/utilities/data_structures/graphics/objects/cursor/data:label_cursor_selection",
        "//code/utilities/data_structures/graphics/objects/label/data:message_value_constraints",
        "//code/utilities/data_structures/graphics/objects/label/data:label_user_state",
        "//code/utilities/data_structures/graphics/objects/label/style:label_styles",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events",
        "//code/utilities/data_structures/position",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_settings",
    ],
)

hcp(
    name = "message_value_constraints",
    deps = [
    ],
)

hcp_pos(
    name = "label",
    deps = [
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
    ],
)
