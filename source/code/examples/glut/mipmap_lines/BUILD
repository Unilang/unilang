package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "izoom",
    srcs = ["izoom.cpp"],
    hdrs = ["izoom.hpp"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":izoom",
        "//code/utilities/formats/sgi:load_rgb",
        "@GL",
        "@glut",
        "@x11",
    ],
)
