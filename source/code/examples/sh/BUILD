package(
    default_visibility = ["//visibility:public"],
)

sh_binary(
    name = "hello_world",
    srcs = ["hello_world.sh"],
)

sh_test(
    name = "hello_world_test",
    size = "small",
    srcs = ["test/hello_world_test.sh"],
    data = [":hello_world"],
)
