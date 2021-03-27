package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
        "//code/programs/transcompilers/hcp-compiler/bootstrap/core/class_structure_creator:lib",
        "//code/programs/transcompilers/hcp-compiler/bootstrap/core/structure:lib",
    ],
)
