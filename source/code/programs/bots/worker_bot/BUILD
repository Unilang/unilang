package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "worker_bot",
    deps = [
        "//code/utilities/build:self_builder",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call/process_spawn:process_spawner",
        "//code/utilities/program/call/process_spawn/timed:timed_process_spawner",
        "//code/utilities/program/wrappers/sendmail:sendmail_sender",
        "//code/utilities/program/wrappers/sendmail:sendmail_settings",
        "//code/utilities/program/wrappers/sendmail:sendmail_settings_getter",
        "//code/utilities/program/wrappers/sendmail:ssmtp_conf_maker",
        "//code/utilities/time/sleeping:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "//code/programs/bots/worker_bot",
        "//code/utilities/program/call:lib",
    ],
)
