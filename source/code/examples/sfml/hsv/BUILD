package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lc++",
    ],
    deps = [
        "//code/utilities/colors/sfml:sfml_color_pick_grid",
        "//code/utilities/colors/sfml:sfml_color_pick_hue_changer",
        "@GL",
        "@sfml",
    ],
)
