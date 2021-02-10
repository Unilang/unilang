package(default_visibility = ["//visibility:public"])

#the project seems to have a general utilities section
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
        "utils/fade.c",
        "utils/async_netdb.c",
        "utils/logo.c",
        "utils/grabclient.c",
    ],
)

cc_library(
    name = "utils",
    srcs = utils_srcs,
    hdrs = utils_hdrs,
    copts = [
        "-DHAVE_CONFIG_H",
        #"-std=c89",
    ],
    includes = [
        ".",
        "hacks",
        "images",
        "utils",
    ],
    deps = [
        "@system//:X11_hdrs",
        "@system//:X11",
        "@system//:KHR_hdrs",

        #"@libXxf86vm",
        "@system//:libXxf86vm",
        #"@xorg_xorgproto",
        "@system//:GL_hdrs",
        "@system//:GL",
        "@system//:GLU_hdrs",
        "@system//:GLU",
        "@freetype2",
        "@fontconfig",
        "@xkbcommon",
        #"@system//:xkbcommon",
        #"@system//:xkbcommon_hdrs",
        "@system//:SM",
        "@system//:ICE",
        "@system//:Xft",
        "@system//:Xt",
        "@system//:Xmu",
        "@system//:Xext",
    ],
)

#something that I think most screensavers need
cc_library(
    name = "screen_hack",
    srcs = [
        "hacks/fps.c",
        "hacks/screenhack.c",
        "hacks/xlockmore.c",
    ],
    hdrs = [
        "hacks/fps.h",
        "hacks/fpsI.h",
        "hacks/screenhack.h",
        "hacks/screenhackI.h",
        "hacks/xlockmore.h",
        "hacks/xlockmoreI.h",
    ],
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        "hacks",
        "utils",
    ],
    deps = [
        ":utils",
    ],
)

cc_library(
    name = "screen_hack2",
    srcs = [
        "hacks/screenhack.c",
        "hacks/fps.c",
        "hacks/xlockmore.c",
    ],
    hdrs = [
        "hacks/fps.h",
        "hacks/fpsI.h",
        "hacks/screenhack.h",
        "hacks/screenhackI.h",
        "hacks/xlockmore.h",
        "hacks/xlockmoreI.h",
    ],
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        "hacks",
        "utils",
    ],
    deps = [
        ":utils",
    ],
)

#try building some individual screensavers
#These are recommended by the author as good starting examples
#If you want to write your own screensavers
cc_binary(
    name = "deluxe",
    srcs = ["hacks/deluxe.c"],
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    deps = [
        ":screen_hack",
        ":utils",
    ],
)

cc_binary(
    name = "greynetic",
    srcs = ["hacks/greynetic.c"],
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    deps = [
        ":screen_hack",
        ":utils",
    ],
)

#This is recomended as a good starting example for OpenGL screensavers
cc_binary(
    name = "dangerball",
    srcs = [
        "hacks/glx/dangerball.c",
        "hacks/glx/fps-gl.c",
        "hacks/glx/gltrackball.c",
        "hacks/glx/gltrackball.h",
        "hacks/glx/rotator.c",
        "hacks/glx/rotator.h",
        "hacks/glx/sphere.c",
        "hacks/glx/sphere.h",
        "hacks/glx/texfont.h",
        "hacks/glx/trackball.c",
        "hacks/glx/trackball.h",
        "hacks/glx/tube.c",
        "hacks/glx/tube.h",
        "hacks/glx/xlock-gl-utils.c",
        "hacks/glx/texfont.c",
        #"hacks/glx/xscreensaver-gl-helper.c",
    ],
    copts = [
        "-DHAVE_CONFIG_H",
        "-DSTANDALONE",
        "-DUSE_GL",
        "-U__STRICT_ANSI__",
        #"-std=c89",
    ],
    deps = [
        ":screen_hack2",
        ":utils",
    ],
)
