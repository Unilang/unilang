package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")

hcp(
    name = "code_pipeline_image_maker",
    deps = [
        "//code/utilities/code:concept_string_tree_getter",
        "//code/utilities/data_structures/graph/conceptually_laid_out_graph",
        "//code/utilities/data_structures/graphics/bitmap/premade:tree_button",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree:buildable_schema_face_tree_drawer",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree:string_tree_to_buildable_schema_faced_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_tree_label_drawer",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:positioned_button_face_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:string_tree_to_buttoned_face_tree",
        "//code/utilities/data_structures/graphics/objects/label/style:default_label_styles",
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/fonts/bdf/complete/unilang:unilang_character_maps",
        "//code/utilities/graphics/cairo/render:cairo_render_settings",
        "//code/utilities/graphics/cairo/render:frame_renderer",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/personal/hosting:hosting_repo",
        "//code/utilities/program/wrappers/convert:image_transparent",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/tree/converters:tree_full_paths_getter",
        "//code/utilities/types/vectors/observers:lib",
        "@tree",
        "//code/utilities/data_structures/graphics/objects/fitted_faced_label_graph:fitted_faced_label_graph_creator",
        "//code/utilities/data_structures/graphics/objects/fitted_faced_label_graph:fitted_faced_label_graph_drawer",
    ],
)
