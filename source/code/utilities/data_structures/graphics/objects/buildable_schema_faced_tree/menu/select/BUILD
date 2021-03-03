package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "schema_tree_menu_click_handler",
    deps = [
        "//code/utilities/code/style_theme",
        "//code/utilities/code/style_theme:style_lookup_map",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree:buildable_face_tree_action_doer",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree:buildable_face_tree_style_applier",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree/data:buildable_face_tree",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree:style_theme_applier",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:global_manipulation_option",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:local_manipulation_option",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:button_faced_label_style_applier",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/premade:buttoned_faced_label_premades",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_full_path_name",
        "//code/utilities/data_structures/graphics/objects/faced_tree:tree_label_click_finder",
        "//code/utilities/data_structures/tree/generic:child_lookup_map",
        "//code/utilities/data_structures/tree/generic:child_lookup_map_find",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_active_pos_finder",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu/select:schema_menu_selection_performer",
        "//code/utilities/fonts/bdf/character_maps:character_maps",
        "//code/utilities/peripheral/pc:pc_input_state",
    ],
)

hcp(
    name = "schema_tree_menu_select_handler",
    deps = [
        "//code/utilities/code/style_theme",
        "//code/utilities/code/style_theme:style_lookup_map",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree:buildable_face_tree_action_doer",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree:buildable_face_tree_style_applier",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree/data:buildable_face_tree",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree:style_theme_applier",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:global_manipulation_option",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:local_manipulation_option",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:button_faced_label_style_applier",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/premade:buttoned_faced_label_premades",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_full_path_name",
        "//code/utilities/data_structures/graphics/objects/faced_tree:tree_label_click_finder",
        "//code/utilities/data_structures/tree/generic:child_lookup_map",
        "//code/utilities/data_structures/tree/generic:child_lookup_map_find",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_active_pos_finder",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu/select:schema_menu_selection_performer",
        "//code/utilities/data_structures/graphics/objects/faced_tree:tree_label_active_finder",
        "//code/utilities/fonts/bdf/character_maps:character_maps",
        "//code/utilities/peripheral/pc:pc_input_state",
    ],
)

hcp(
    name = "schema_menu_selection_performer",
    deps = [
        "//code/utilities/code/style_theme",
        "//code/utilities/code/style_theme:style_lookup_map",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree:buildable_face_tree_action_doer",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree:buildable_face_tree_style_applier",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree/data:buildable_face_tree",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree:style_theme_applier",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:global_manipulation_option",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:local_manipulation_option",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:button_faced_label_style_applier",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/premade:buttoned_faced_label_premades",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_full_path_name",
        "//code/utilities/data_structures/graphics/objects/faced_tree:tree_label_click_finder",
        "//code/utilities/data_structures/tree/generic:child_lookup_map",
        "//code/utilities/data_structures/tree/generic:child_lookup_map_find",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_active_pos_finder",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_set_active",
        "//code/utilities/fonts/bdf/character_maps:character_maps",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_highlight_text",
    ],
)
