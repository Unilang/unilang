package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")
load("//bazel/rules/hcp:hcp.bzl", "hcp")

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

hcp(
    name = "grice_cooperative_principle_maxim",
    deps = [
        "//code/utilities/linguistics/cooperative_principle:grice_cooperative_principle_maxims",
        "//code/utilities/linguistics/cooperative_principle:grice_cooperative_principle_maxim_actions",
    ],
)
