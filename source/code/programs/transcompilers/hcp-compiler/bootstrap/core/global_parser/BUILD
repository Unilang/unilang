package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
        "//code/programs/transcompilers/hcp-compiler/bootstrap/core/global_structure_creator:lib",
        "//code/programs/transcompilers/hcp-compiler/bootstrap/core/structure:lib",
    ],
)
