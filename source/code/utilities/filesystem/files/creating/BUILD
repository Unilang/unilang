package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
        "//code/tools/reflexivity/comment:generated_comment_getter",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/types/strings/transformers/stripping:lib",
    ],
)
