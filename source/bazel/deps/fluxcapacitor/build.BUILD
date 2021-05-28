cc_library(
    name = "preload",
    srcs =
        [
            "src/preload.c",
            "src/types.h",
            "src/scnums.h",
            "src/scnums_amd64.h",
            "src/scnums_arm.h",
            "src/scnums_x86.h",
        ],
    includes = [
        ".",
        "src",
    ],
    visibility = ["//visibility:public"],
)


cc_binary(
    name = "fluxcapacitor",
    srcs =
        [
            "src/fluxcapacitor.h",
            "src/list.h",
            "src/main.c",
            "src/misc.c",
            "src/parent.c",
            "src/scnums.h",
            "src/scnums_amd64.h",
            "src/trace.c",
            "src/trace.h",
            "src/types.h",
            "src/uevent.c",
            "src/preload.c",
            "src/uevent.h",
            "src/wrapper.c",
        ],
    deps = [":preload"],
    includes = [
        ".",
        "src",
    ],
    visibility = ["//visibility:public"],
)
