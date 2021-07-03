package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "gui_desktop",
    deps = [
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
        "//code/utilities/data_structures/graphics/gui_desktop:file_save_state",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree/data:positioned_buildable_face_tree",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/data:positioned_buildable_schema_faced_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree/data:positioned_button_face_tree",
        "//code/utilities/data_structures/graphics/objects/cursor/data:cursor",
        "//code/utilities/data_structures/graphics/objects/cursor/data:label_cursor",
        "//code/utilities/data_structures/graphics/objects/faced_grid:positioned_face_grid",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_tree:positioned_face_tree",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/data_structures/graphics/objects/label/data:positioned_label",
        "//code/utilities/data_structures/graphics/objects/mouse:anchor_mouse",
        "//code/utilities/data_structures/graphics/objects/mouse:cursor_mouse_connector",
        "//code/utilities/data_structures/graphics/objects/mouse:mouse_selection",
        "//code/utilities/data_structures/graphics/objects/select_menu:positioned_select_menu",
        "//code/utilities/data_structures/graphics/objects/slider:positioned_slider",
        "//code/utilities/data_structures/position",
        "//code/utilities/data_structures/shapes/rectangle:shade_rectangle_settings",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/graphics/imgui/background:background_settings",
        "//code/utilities/graphics/imgui/window:window_settings",
        "//code/utilities/graphics/sdl:sdl_init_settings",
        "//code/utilities/peripheral/pc:pc_input_state",
        "@boost//:asio",
    ],
)

hcp(
    name = "gui_desktop_getter",
    deps = [
        "//code/utilities/data_structures/graphics/gui_desktop",
        "//code/utilities/data_structures/graphics/objects/mouse/premade:standard_mouse",
        "//code/utilities/execution:thread_pool_getter",
        "//code/utilities/fonts/bdf/complete/unilang:unilang_character_maps",
        "//code/utilities/graphics/imgui/background:background_settings_getter",
        "//code/utilities/graphics/sdl:standard_sdl_init_settings",
    ],
)

hcp(
    name = "file_save_state",
    deps = [
    ],
)
