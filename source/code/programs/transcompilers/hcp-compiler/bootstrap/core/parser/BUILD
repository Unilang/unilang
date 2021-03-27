package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
        "//code/programs/transcompilers/hcp-compiler/bootstrap/core/class_parser:lib",
        "//code/programs/transcompilers/hcp-compiler/bootstrap/core/global_parser:lib",
        "//code/utilities/program/common_actions/exits:lib",
    ],
)
