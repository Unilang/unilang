package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "ide_settings",
    deps = [
        "//code/programs/ide/global_actions:global_action",
        "//code/programs/ide/settings/data:ide_elements",
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
        "//code/utilities/data_structures/graphics/gui_desktop",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree/data:positioned_buildable_face_tree",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/data:positioned_buildable_schema_faced_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:positioned_button_face_tree",
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
    name = "ide_elements",
    deps = [
        "//code/programs/ide/settings/data:ide_element",
        "//code/utilities/data_structures/graphics/bitmap/full_color_bitmap:positioned_full_color_bitmap",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree/data:positioned_buildable_face_tree",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/data:positioned_buildable_schema_faced_tree",
        "//code/utilities/data_structures/shapes/rectangle:positioned_rectangle_settings",
    ],
)

hcp(
    name = "ide_element",
    deps = [
        "//code/utilities/data_structures/graphics/bitmap/full_color_bitmap:positioned_full_color_bitmap",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
        "//code/utilities/data_structures/graphics/image:positioned_animated_image_data",
        "//code/utilities/data_structures/graphics/image:positioned_image_data",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree/data:positioned_buildable_face_tree",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/data:positioned_buildable_schema_faced_tree",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/formats/json/overloads:variant_json_converters",
    ],
)

hcp(
    name = "ide_creation_settings",
    deps = [
    ],
)
