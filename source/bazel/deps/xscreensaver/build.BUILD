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
        "@system//:X11",
        "@system//:KHR_hdrs",
        
        "@libXxf86vm",
        #"@system//:libXxf86vm",
        
        "@system//:GL_hdrs",
        "@freetype2",
        "@fontconfig",
        
        "@xkbcommon",
        #"@system//:xkbcommon",
        #"@system//:xkbcommon_hdrs",
    ],
)


#something that I think most screensavers need
cc_library(
    name = "screen_hack",
    hdrs = ["hacks/screenhack.h", "hacks/screenhackI.h", "hacks/fps.h", "hacks/fpsI.h", "hacks/xlockmore.h", "hacks/xlockmoreI.h"],
    srcs = [
    "hacks/screenhack.c",
    "hacks/fps.c",
    "hacks/xlockmore.c"],
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
    hdrs = ["hacks/screenhack.h", "hacks/screenhackI.h", "hacks/fps.h", "hacks/fpsI.h", "hacks/xlockmore.h", "hacks/xlockmoreI.h"],
    srcs = [
    #"hacks/screenhack.c",
    "hacks/fps.c",
    "hacks/xlockmore.c"],
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
    ":utils",":screen_hack",],
)

cc_binary(
    name = "greynetic",
    srcs = ["hacks/greynetic.c"],
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    deps = [
    ":utils",":screen_hack",],
)

#This is recomended as a good starting example for OpenGL screensavers
cc_binary(
    name = "dangerball",
    srcs = ["hacks/glx/dangerball.c","hacks/glx/sphere.h","hacks/glx/tube.h","hacks/glx/rotator.h","hacks/glx/gltrackball.h"],
    copts = [
        "-DHAVE_CONFIG_H",
        #"-DSTANDALONE",
        #"-U__STRICT_ANSI__",
        #"-std=c89",
    ],
    deps = [
    ":utils",":screen_hack2",],
)