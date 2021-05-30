cc_binary(
    name = "tardis",
    srcs = ["tardis.c"],
    data = [":tardis_preload"],
    includes = ["."],
    visibility = ["//visibility:public"],
    deps = [":tardis_preload"],
)

cc_library(
    name = "tardis_preload",
    srcs = ["novdso.c"],
    includes = ["."],
    visibility = ["//visibility:public"],
)
