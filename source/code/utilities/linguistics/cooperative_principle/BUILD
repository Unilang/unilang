package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "grice_cooperative_principle_maxims",
    values = [
        "quality",
        "quantity",
        "manner",
        "relevance",
    ],
)

enum_cpp(
    name = "grice_cooperative_principle_maxim_actions",
    values = [
        "follow",
        "flout",
        "violate",
        "opt_out",
    ],
)