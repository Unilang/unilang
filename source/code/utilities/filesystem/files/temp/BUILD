package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "temp_file",
    srcs = ["temp_file.cpp"],
    hdrs = ["temp_file.hpp"],
    deps = [
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/deleting:lib",
    ],
)

cc_library(
    name = "existing_temp_file",
    srcs = ["existing_temp_file.cpp"],
    hdrs = ["existing_temp_file.hpp"],
    deps = [
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/deleting:lib",
    ],
)

cc_library(
    name = "temp_dir",
    srcs = ["temp_dir.cpp"],
    hdrs = ["temp_dir.hpp"],
    deps = [
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/deleting:lib",
        "//code/utilities/random/files:random_files",
        "//code/utilities/filesystem/paths:lib",
    ],
)
