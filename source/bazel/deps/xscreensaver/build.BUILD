package(default_visibility = ["//visibility:public"])

# hdrs = glob(
#     include = [
#         "include/**/*.h",
#     ],
#     exclude = [
#     ],
# )

# cc_library(
#     name = "screen_hack",
#     hdrs = ["hacks/screenhack.h", "hacks/screenhackI.h", "utils/yarandom.h", "utils/usleep.h", "utils/resources.h", "utils/hsv.h", "utils/colors.h"],
#     srcs = ["hacks/screenhack.c"],
#     copts = [
#     ],
#     includes = [
#         "hacks",
#         "utils",
#     ],
#     deps = [
#         "@system//:X11_hdrs"
#     ],
# )

# cc_binary(
#     name = "deluxe",
#     srcs = ["hacks/deluxe.c"],
#     deps = [":screen_hack",
#     "@system//:X11_hdrs",],
# )


utils_hdrs = glob(
    include = [
        "utils/**/*.h",
        "hacks/ximage-loader.h",
        "images/**/*.xpm",
    ],
    exclude = [
    ],
)

utils_srcs = glob(
    include = [
        "utils/**/*.c",
    ],
    exclude = [
        "utils/vms-gtod.c",
        "utils/yarandom.c",
        "utils/fade.c",
        "utils/async_netdb.c",
        "utils/logo.c",
        "utils/grabclient.c",
    ],
)

cc_library(
    name = "utils",
    hdrs = utils_hdrs,
    srcs = utils_srcs,
    copts = [
        "-DHAVE_CONFIG_H",
        #"-std=c89",
    ],
    includes = [
        "utils",
        "hacks",
        "images",
        ".",
    ],
    deps = [
        "@system//:X11_hdrs",
        "@system//:KHR_hdrs",
        "@libXxf86vm",
        "@system//:GL_hdrs",
        "@freetype2",
        "@fontconfig",
    ],
)
