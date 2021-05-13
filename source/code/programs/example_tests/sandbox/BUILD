package(
    default_visibility = ["//visibility:public"],
)

sh_test(
    name = "no_use_sandbox",
    srcs = ["no_use_sandbox.sh"],
)

sh_test(
    name = "use_sandbox",
    srcs = ["use_sandbox.sh"],
    exec_properties = {"linux-sandbox": "True"},
)
