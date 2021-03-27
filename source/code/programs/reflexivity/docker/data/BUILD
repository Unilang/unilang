package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "apt_get_command",
    deps = [],
)

hcp(
    name = "apt_ppa_command",
    deps = [],
)

hcp(
    name = "apt_get_commands_getter",
    deps = [
        "//code/programs/reflexivity/docker/data:apt_get_command",
    ],
)

hcp(
    name = "apt_ppa_commands_getter",
    deps = [
        "//code/programs/reflexivity/docker/data:apt_ppa_command",
    ],
)

hcp(
    name = "docker_settings",
    deps = [
        "//code/programs/reflexivity/docker/data:apt_get_command",
        "//code/programs/reflexivity/docker/data:apt_ppa_command",
    ],
)

hcp(
    name = "docker_settings_getter",
    deps = [
        "//code/programs/reflexivity/docker/data:apt_get_commands_getter",
        "//code/programs/reflexivity/docker/data:apt_ppa_commands_getter",
        "//code/programs/reflexivity/docker/data:docker_settings",
    ],
)
