package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = [
        "a.c",
        "b.c",
        "d.c",
        "draw_holder.c",
        "draw_lamp.c",
        "draw_logo.c",
        "draw_logo_line.c",
        "draw_logo_shadow.c",
        "e.c",
        "f.c",
        "h.c",
        "i.c",
        "m.c",
        "n.c",
        "o.c",
        "p.c",
        "r.c",
        "s.c",
        "t.c",
        "w.c",
    ],
    hdrs = [
        "objects.h",
    ],
    deps = [
        "@glut",
        "@x11",
    ],
)

cc_binary(
    name = "main",
    srcs = ["track.c"],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":lib",
        "@GL",
        "@glut",
        "@x11",
    ],
)
