package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "convert_image_maker",
    deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/convert/settings:image_settings",
    ],
)

hcp(
    name = "draw_text_on_image",
    deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/convert/settings:draw_text_settings",
        "//code/utilities/program/wrappers/convert/settings:image_settings",
        "//code/utilities/types/strings/transformers/wrap:lib",
    ],
)

hcp(
    name = "whitespace_image_trimmer",
    deps = [
        "//code/utilities/program/call:lib",
    ],
)

hcp(
    name = "image_transparent",
    deps = [
        "//code/utilities/program/call:lib",
    ],
)

hcp(
    name = "black_and_white_forcer",
    deps = [
        "//code/utilities/program/call:lib",
    ],
)

hcp(
    name = "convert_image_animator",
    deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/convert/settings:image_settings",
        "//code/utilities/program/wrappers/convert/settings:image_animated_settings",
    ],
)