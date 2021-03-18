package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")

hcp(
    name = "faced_label_premades",
    deps = [
        "//code/tools/ide/settings:ide_settings",
        "//code/utilities/colors/defaults:color_defaults",
        "//code/utilities/colors/defaults:rectangle_shades",
        "//code/utilities/data_structures/graphics/bitmap/full_color_bitmap",
        "//code/utilities/data_structures/graphics/bitmap/pixel:pixel_slider",
        "//code/utilities/data_structures/graphics/objects/cursor/premade:blue_cursor",
        "//code/utilities/data_structures/graphics/objects/cursor/premade:red_cursor",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/data_structures/graphics/objects/label/style:default_label_styles",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/data_structures/graphics/text:text_to_bitmap",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/graphics/imgui:ui_renders",
        "//code/utilities/graphics/imgui/render/elements:full_color_bitmap_drawer",
        "//code/utilities/graphics/imgui/render/elements:rectangle_drawer",
        "//code/utilities/data_structures/graphics/objects/cursor/data:default_cursor_ability",
    ],
)
