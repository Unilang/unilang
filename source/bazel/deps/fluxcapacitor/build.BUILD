cc_library(
    name = "preload",
    srcs =
        [
            "src/preload.c",
            "src/scnums.h",
            "src/scnums_amd64.h",
            "src/scnums_arm.h",
            "src/scnums_x86.h",
            "src/types.h",
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
            "src/preload.c",
            "src/scnums.h",
            "src/scnums_amd64.h",
            "src/trace.c",
            "src/trace.h",
            "src/types.h",
            "src/uevent.c",
            "src/uevent.h",
            "src/wrapper.c",
        ],
    includes = [
        ".",
        "src",
    ],
    visibility = ["//visibility:public"],
    deps = [":preload"],
)
