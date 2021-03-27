package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "core",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
        "//code/programs/transcompilers/hcp-compiler/bootstrap/core/compiler:lib",
        "//code/programs/transcompilers/hcp-compiler/bootstrap/core/parser:lib",
        "//code/programs/transcompilers/hcp-compiler/bootstrap/program_options:lib",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/strings/observers/path:lib",
    ],
)
