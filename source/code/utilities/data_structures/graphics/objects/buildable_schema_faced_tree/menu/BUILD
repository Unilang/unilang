package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "schema_menu_type",
    values = [
        "global",
        "local",
        "rename",
        "insert",
    ],
)

enum_cpp(
    name = "global_manipulation_option",
    values = [
        "draw_children_only",
        "draw_signified_only",
        "draw_all",
        "apply_color_theme",
        "sort_by_schema",
    ],
)

enum_cpp(
    name = "local_manipulation_option",
    values = [
        "delete",
        "duplicate",
        "up",
        "down",
        "first",
        "last",
    ],
)

enum_cpp(
    name = "schema_menu_open_strategy",
    values = [
        "at_mouse",
        "alongside",
        "dont_open",
    ],
)

hcp(
    name = "schema_tree_menu_creation_settings",
    deps = [
    ],
)

hcp(
    name = "schema_menu_handler",
    deps = [
        "//code/utilities/code/style_theme:style_lookup_map",
        "//code/utilities/data_structures/counters/unique_max_counter",
        "//code/utilities/data_structures/graphics/bitmap/premade:horizontal_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:l_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:vertical_line",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree:buildable_face_tree_action_doer",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree:buildable_label_action",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree/data:buildable_face_tree",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree/data:positioned_buildable_face_tree",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:schema_menu_type",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:schema_tree_menu_click_handler",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:schema_tree_menu_select_handler",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:schema_tree_menu_creation_settings",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:schema_tree_menu_creator",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:positioned_buttoned_faced_label",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/premade:buttoned_faced_label_premades",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_click_finder",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_full_path_name",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_tree_label_drawer",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:positioned_button_face_tree",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
        "//code/utilities/data_structures/graphics/objects/faced_label/premade:faced_label_premades",
        "//code/utilities/data_structures/graphics/objects/faced_tree:tree_label_click_finder",
        "//code/utilities/data_structures/graphics/objects/faced_tree:tree_label_drawer",
        "//code/utilities/data_structures/graphics/objects/label:label_drawer",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/data_structures/graphics/objects/select_menu",
        "//code/utilities/data_structures/tree/generic:child_lookup_map",
        "//code/utilities/data_structures/tree/generic:child_lookup_map_find",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/output/printers:lib",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/types/tree:full_path_name",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:schema_menu_open_strategy",
        "//code/utilities/data_structures/graphics/objects/faced_tree:faced_tree_next_active",
        "//code/utilities/data_structures/graphics/objects/faced_tree:faced_tree_previous_active",
    ],
)

hcp(
    name = "schema_tree_menu_creator",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:global_manipulation_option",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:local_manipulation_option",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:schema_tree_menu_creation_settings",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_full_path_name",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:positioned_button_face_tree",
        "//code/utilities/data_structures/graphics/objects/faced_label/premade:faced_label_premades",
        "//code/utilities/data_structures/graphics/objects/select_menu",
        "//code/utilities/data_structures/tree/generic:child_lookup_map",
        "//code/utilities/data_structures/tree/generic:child_lookup_map_find",
    ],
)

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
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:schema_menu_selection_performer",
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
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:schema_menu_selection_performer",
        "//code/utilities/data_structures/graphics/objects/faced_tree:tree_label_active_finder",
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
    ],
)

hcp(
    name = "schema_menu_should_open",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/data:buildable_schema_faced_tree",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/data:positioned_buildable_schema_faced_tree",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_click_finder",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_active_finder",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/menu:schema_menu_open_strategy",
    ],
)
