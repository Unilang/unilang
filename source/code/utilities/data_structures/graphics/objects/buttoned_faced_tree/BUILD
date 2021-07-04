package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "button_face_tree_range",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree",
    ],
)

hcp(
    name = "positioned_button_tree_iterator",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:buttoned_faced_label",
        "//code/utilities/data_structures/line_break:should_line_break",
        "@tree",
    ],
)

hcp(
    name = "button_face_tree_drawer",
    deps = [
        "//code/utilities/code/references:reference_lookup_map",
        "//code/utilities/data_structures/counters/unique_max_counter",
        "//code/utilities/data_structures/graphics/bitmap/premade:horizontal_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:l_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:left_arrow",
        "//code/utilities/data_structures/graphics/bitmap/premade:right_arrow",
        "//code/utilities/data_structures/graphics/bitmap/premade:vertical_line",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:buttoned_faced_label_drawer",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:buttoned_faced_label_is_active",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:positioned_buttoned_faced_label",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_full_path_name",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_range",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_tree_global_navigation",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:draw_strategy",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:for_each_noncollapsed",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:positioned_button_face_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:positioned_button_tree_iterator",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_eventer",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_is_active",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_set_active",
        "//code/utilities/data_structures/graphics/objects/label:label_drawer",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/math",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_connection_drawer",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_drawer_wide",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_drawer_regular",
    ],
)

hcp(
    name = "button_face_tree_drawer_regular",
    deps = [
        "//code/utilities/code/references:reference_lookup_map",
        "//code/utilities/data_structures/counters/unique_max_counter",
        "//code/utilities/data_structures/graphics/bitmap/premade:horizontal_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:l_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:left_arrow",
        "//code/utilities/data_structures/graphics/bitmap/premade:right_arrow",
        "//code/utilities/data_structures/graphics/bitmap/premade:vertical_line",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:buttoned_faced_label_drawer",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:buttoned_faced_label_is_active",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:positioned_buttoned_faced_label",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_full_path_name",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_range",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_tree_global_navigation",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:draw_strategy",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:for_each_noncollapsed",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:positioned_button_face_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:positioned_button_tree_iterator",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_eventer",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_is_active",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_set_active",
        "//code/utilities/data_structures/graphics/objects/label:label_drawer",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/math",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_connection_drawer",
    ],
)

hcp(
    name = "button_face_tree_drawer_wide",
    deps = [
        "//code/utilities/code/references:reference_lookup_map",
        "//code/utilities/data_structures/counters/unique_max_counter",
        "//code/utilities/data_structures/graphics/bitmap/premade:horizontal_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:l_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:left_arrow",
        "//code/utilities/data_structures/graphics/bitmap/premade:right_arrow",
        "//code/utilities/data_structures/graphics/bitmap/premade:vertical_line",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:buttoned_faced_label_drawer",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:buttoned_faced_label_is_active",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:positioned_buttoned_faced_label",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_full_path_name",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_range",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_tree_global_navigation",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:draw_strategy",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:for_each_noncollapsed",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:positioned_button_face_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:positioned_button_tree_iterator",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_eventer",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_is_active",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_set_active",
        "//code/utilities/data_structures/graphics/objects/label:label_drawer",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/math",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_connection_drawer",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "button_face_tree_connection_drawer",
    deps = [
        "//code/utilities/code/references:reference_lookup_map",
        "//code/utilities/data_structures/counters/unique_max_counter",
        "//code/utilities/data_structures/graphics/bitmap/premade:horizontal_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:l_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:left_arrow",
        "//code/utilities/data_structures/graphics/bitmap/premade:right_arrow",
        "//code/utilities/data_structures/graphics/bitmap/premade:vertical_line",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:buttoned_faced_label_drawer",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:buttoned_faced_label_is_active",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:positioned_buttoned_faced_label",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_full_path_name",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_range",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_tree_global_navigation",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:draw_strategy",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:for_each_noncollapsed",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:positioned_button_face_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:positioned_button_tree_iterator",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_eventer",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_is_active",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_set_active",
        "//code/utilities/data_structures/graphics/objects/label:label_drawer",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/math",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "button_face_tree_set_active",
    deps = [
        "//code/utilities/data_structures/counters/unique_max_counter",
        "//code/utilities/data_structures/graphics/bitmap/premade:horizontal_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:l_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:right_arrow",
        "//code/utilities/data_structures/graphics/bitmap/premade:vertical_line",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:buttoned_faced_label_drawer",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:buttoned_faced_label_is_active",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:positioned_buttoned_faced_label",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_tree_global_navigation",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:for_each_noncollapsed",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:positioned_button_face_tree",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_eventer",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_is_active",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_set_active",
        "//code/utilities/data_structures/graphics/objects/label:label_drawer",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "button_face_tree_active_pos_finder",
    deps = [
        "//code/utilities/data_structures/counters/unique_max_counter",
        "//code/utilities/data_structures/graphics/bitmap/premade:horizontal_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:l_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:right_arrow",
        "//code/utilities/data_structures/graphics/bitmap/premade:vertical_line",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:buttoned_faced_label_drawer",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:buttoned_faced_label_is_active",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:positioned_buttoned_faced_label",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_tree_global_navigation",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:for_each_noncollapsed",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:positioned_button_face_tree",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_eventer",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_is_active",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_set_active",
        "//code/utilities/data_structures/graphics/objects/label:label_drawer",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "button_tree_global_navigation",
    deps = [
        "//code/utilities/data_structures/counters/unique_max_counter",
        "//code/utilities/data_structures/graphics/bitmap/premade:horizontal_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:l_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:right_arrow",
        "//code/utilities/data_structures/graphics/bitmap/premade:vertical_line",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:buttoned_faced_label_is_active",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:buttoned_faced_label_toggle_button",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:positioned_buttoned_faced_label",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_action",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_action_decider",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:positioned_button_face_tree",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_is_active",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_is_enabled",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_set_active",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_set_enabled",
        "//code/utilities/data_structures/graphics/objects/label:label_drawer",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "buttoned_faced_tree_is_mouse_over",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:buttoned_faced_label_is_mouse_over",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:buttoned_faced_label",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:for_each_noncollapsed",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:positioned_button_face_tree",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "for_each_noncollapsed",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:buttoned_faced_label",
        "//code/utilities/data_structures/should_break",
        "@tree",
    ],
)

hcp(
    name = "button_face_tree_click_finder",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:buttoned_faced_label",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree",
        "@tree",
    ],
)

hcp(
    name = "button_face_tree_active_finder",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:buttoned_faced_label",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree",
        "@tree",
    ],
)

hcp(
    name = "button_face_tree_full_path_name",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:buttoned_faced_label",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree",
        "@tree",
    ],
)

hcp(
    name = "button_face_tree_tokenizer",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:buttoned_faced_label_is_enabled",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:buttoned_faced_label",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_first_name",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_message",
        "//code/utilities/data_structures/tree/generic/tokens:tree_token",
        "@tree",
    ],
)

hcp(
    name = "string_tree_to_buttoned_face_tree",
    deps = [
        "//code/utilities/code:concept_string_tree_getter",
        "//code/utilities/data_structures/graphics/bitmap/premade:tree_button",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_drawer",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:positioned_button_face_tree",
        "//code/utilities/data_structures/graphics/objects/label/style:default_label_styles",
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/fonts/bdf/complete/unilang:unilang_character_maps",
        "//code/utilities/graphics/cairo/render:cairo_render_settings",
        "//code/utilities/graphics/cairo/render:frame_renderer",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/personal/hosting:hosting_repo",
        "//code/utilities/types/tree/converters:tree_full_paths_getter",
        "@tree",
    ],
)

hcp(
    name = "button_face_tree_action_decider",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_action",
        "//code/utilities/peripheral/pc:pc_input_state",
    ],
)

enum_cpp(
    name = "button_face_tree_action",
    values = [
        "down_activation",
        "up_activation",
        "collapse_toggle",
        "enable_toggle",
        "delete",
        "none",
    ],
)

hcp(
    name = "button_face_tree_style_applier",
    deps = [
        "//code/utilities/code/style_theme",
        "//code/utilities/code/style_theme:style_lookup_map",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree:buildable_face_tree_action_doer",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:button_faced_label_style_applier",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/premade:buttoned_faced_label_premades",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_full_path_name",
        "//code/utilities/data_structures/graphics/objects/faced_tree:tree_label_click_finder",
        "//code/utilities/data_structures/tree/generic:child_lookup_map",
        "//code/utilities/data_structures/tree/generic:child_lookup_map_find",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "button_face_tree_first_face_no_edit",
    deps = [
        "//code/utilities/code/style_theme",
        "//code/utilities/code/style_theme:style_lookup_map",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree:buildable_face_tree_action_doer",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:buttoned_faced_label_first_face_no_edit",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/premade:buttoned_faced_label_premades",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:button_face_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_full_path_name",
        "//code/utilities/data_structures/graphics/objects/faced_tree:tree_label_click_finder",
        "//code/utilities/data_structures/tree/generic:child_lookup_map",
        "//code/utilities/data_structures/tree/generic:child_lookup_map_find",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)
