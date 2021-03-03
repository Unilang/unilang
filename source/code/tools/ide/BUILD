load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp(
    name = "unilang_ide",
    deps = [
        "//code/tools/ide:gl_context_element_load",
        "//code/tools/ide/frame:frame_logic_updater",
        "//code/tools/ide/global_actions:global_action_handler",
        "//code/tools/ide/global_actions:save_state_serializer",
        "//code/tools/ide/program_options:lib",
        "//code/tools/ide/settings:ide_settings",
        "//code/tools/ide/settings:ide_default_settings_getter",
        "//code/tools/ide/settings:ide_settings_getter",
        "//code/utilities/data_structures/graphics/image:positioned_image_data",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/graphics/imgui:ui_renders",
        "//code/utilities/graphics/imgui/loop:mechanics",
        "//code/utilities/graphics/imgui/render:frame_renderer",
        "//code/utilities/image:stb_image_setter",
        "@imgui//:imgui_sdl_opengl3",
    ],
)

hcp(
    name = "gl_context_element_load",
    deps = [
        "//code/tools/ide/settings:ide_element",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/image:stb_animated_image_setter",
        "//code/utilities/image:stb_image_setter",
        "//code/utilities/types/variant:lib",
    ],
)

cpp_main(
    name = "main",
    deps = [
        "//code/tools/ide:unilang_ide",
        "//code/tools/ide/program_options:lib",
    ],
)
