package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")

hcp_and_hcp_pos(
    name = "face_tree",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/line_break:should_line_break",
        "@tree",
    ],
)

hcp(
    name = "tree_label_drawer",
    deps = [
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_eventer",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_tree:face_tree",
        "//code/utilities/data_structures/graphics/objects/faced_tree:positioned_face_tree",
        "//code/utilities/data_structures/graphics/objects/label:label_drawer",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "tree_label_click_finder",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_tree:face_tree",
        "@tree",
    ],
)

hcp(
    name = "tree_label_active_finder",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_tree:face_tree",
        "@tree",
    ],
)

hcp(
    name = "faced_tree_next_active",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_tree:face_tree",
        "@tree",
    ],
)

hcp(
    name = "faced_tree_previous_active",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_tree:face_tree",
        "@tree",
    ],
)


