package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")

hcp(
    name = "faced_label_converter",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
    ],
)

hcp(
    name = "faced_label_is_active",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
    ],
)

hcp(
    name = "faced_label_is_enabled",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
    ],
)

hcp(
    name = "faced_label_set_active",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_set_cursor",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label/style:label_style_chooser",
    ],
)

hcp(
    name = "faced_label_set_enabled",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_set_cursor",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label/style:label_style_chooser",
    ],
)

hcp(
    name = "faced_label_first_name",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_set_cursor",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label/style:label_style_chooser",
    ],
)

hcp(
    name = "faced_label_message",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_set_cursor",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label/style:label_style_chooser",
    ],
)

hcp(
    name = "faced_label_set_cursor",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label/style:label_style_chooser",
    ],
)

hcp(
    name = "faced_label_drawer",
    deps = [
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label:label_dimension_getter",
        "//code/utilities/data_structures/graphics/objects/label:label_drawer",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/peripheral/mouse/state:mouse_state",
    ],
)

hcp(
    name = "faced_label_eventer",
    deps = [
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label:label_apply_events",
        "//code/utilities/data_structures/graphics/objects/label:label_dimension_getter",
        "//code/utilities/data_structures/graphics/objects/label:label_drawer",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/peripheral/mouse/state:mouse_state",
    ],
)

hcp(
    name = "faced_label_is_mouse_over",
    deps = [
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label:label_dimension_getter",
        "//code/utilities/data_structures/graphics/objects/label:label_drawer",
        "//code/utilities/data_structures/graphics/objects/label:label_is_mouse_over",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/peripheral/mouse/state:mouse_state",
    ],
)

hcp(
    name = "faced_label_highlight_text",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/fonts/bdf/character_maps:character_maps",
        "//code/utilities/data_structures/graphics/objects/cursor:label_cursor_action_doer",
    ],
)
