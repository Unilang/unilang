package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "label_cursor_mover",
    deps = [
        "//code/utilities/data_structures/graphics/objects/cursor/data:label_cursor_selection",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/data_structures/graphics/text:str_to_bdf_segments",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/fonts/bdf/settings:character_segment",
    ],
)

hcp(
    name = "cursor_drawer",
    deps = [
        "//code/programs/ide/settings/data:ide_settings",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/cursor:label_cursor_action_doer",
        "//code/utilities/data_structures/graphics/objects/mouse/draw:mouse_frame_getter",
        "//code/utilities/data_structures/graphics/objects/mouse/draw:mouse_selection_drawer",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/graphics/imgui/window:window_position_finder",
        "//code/utilities/peripheral/mouse/state:mouse_position_getter",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "label_cursor_action_doer",
    deps = [
        "//code/programs/ide/settings/data:ide_settings",
        "//code/utilities/data_structures/graphics/objects/cursor:label_cursor_actions",
        "//code/utilities/data_structures/graphics/objects/cursor:label_cursor_mover",
        "//code/utilities/data_structures/graphics/objects/cursor:text_box_action_decider",
        "//code/utilities/data_structures/graphics/objects/label/data:positioned_label",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/graphics/imgui:ui_renders",
        "//code/utilities/graphics/imgui/loop:mechanics",
        "//code/utilities/graphics/imgui/window:window_position_finder",
        "//code/utilities/graphics/imgui/window:window_renderer",
        "//code/utilities/peripheral/keyboard:key_detector",
        "//code/utilities/peripheral/pc:pc_input_state",
        "@imgui//:imgui_sdl_opengl3",
    ],
)

hcp(
    name = "label_cursor_actions",
    deps = [
        "//code/programs/ide/settings/data:ide_settings",
        "//code/utilities/data_structures/graphics/objects/cursor:label_cursor_mover",
        "//code/utilities/data_structures/graphics/objects/cursor:text_box_action_decider",
        "//code/utilities/data_structures/graphics/objects/label/data:positioned_label",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/graphics/imgui:ui_renders",
        "//code/utilities/graphics/imgui/loop:mechanics",
        "//code/utilities/graphics/imgui/window:window_position_finder",
        "//code/utilities/graphics/imgui/window:window_renderer",
        "//code/utilities/peripheral/keyboard:key_detector",
        "//code/utilities/peripheral/pc:pc_input_state",
        "@imgui//:imgui_sdl_opengl3",
    ],
)

enum_cpp(
    name = "text_box_action",
    values = [
        "navigate_forward",
        "navigate_backward",
        "select_forward",
        "select_backward",
        "add_chars",
        "backspace",
        "select_all",
        "copy",
        "paste",
        "delete",
        "none",
    ],
)

hcp(
    name = "text_box_action_decider",
    deps = [
        "//code/utilities/data_structures/graphics/objects/cursor:text_box_action",
        "//code/utilities/data_structures/graphics/objects/mouse:anchor_mouse",
        "//code/utilities/graphics/imgui/loop:mechanics",
        "//code/utilities/peripheral/keyboard:key_detector",
        "//code/utilities/peripheral/pc:pc_input_state",
    ],
)
