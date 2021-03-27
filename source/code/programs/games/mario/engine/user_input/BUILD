package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")

hcp(
    name = "user_action",
    deps = [
    ],
)

hcp(
    name = "user_action_getter",
    deps = [
        "//code/programs/games/mario/engine/user_input:user_action",
        "//code/utilities/graphics/x11/data:main_x11_state",
        "//code/utilities/graphics/x11/events:global_event_listener",
        "//code/utilities/types/booleans:lib",
    ],
)
