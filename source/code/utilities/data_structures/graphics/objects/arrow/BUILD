package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "arrow_drawer",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graph/conceptually_laid_out_graph:conceptually_laid_out_graph",
        "//code/utilities/data_structures/graphics/objects/fitted_faced_label_graph/data:fitted_faced_label_graph",
        "//code/utilities/data_structures/graphics/objects/fitted_faced_label_graph/data:positioned_fitted_faced_label_graph",
        "//code/utilities/data_structures/graphics/objects/faced_label/premade:faced_label_premades",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_dimension_getter",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_first_name",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/fonts/bdf/character_maps:character_maps",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/data_structures/graphics/bitmap/premade:vertical_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:horizontal_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:l_line",
        "//code/utilities/data_structures/graphics/bitmap/premade:right_arrow",
        "//code/utilities/data_structures/graphics/bitmap/premade:left_arrow",
        "//code/utilities/data_structures/graphics/objects/arrow/data:arrow",
    ],
)