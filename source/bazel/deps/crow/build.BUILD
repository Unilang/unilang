package(default_visibility = ["//visibility:public"])

cc_library(
    name = "crow",
    hdrs = glob([
        "include/**/*.h",
        "include/**/*.hpp",
    ]),
    includes = ["include"],
)

filegroup (
          name = "example_chat_html",
          srcs = ["examples/example_chat.html"]
)

cc_binary(
    name = "example_chat",
    srcs = ["examples/example_chat.cpp"],
    data = [":example_chat_html"],
    deps = [":crow",
           "@boost//:algorithm",
           "@boost//:asio",
           "@boost//:optional",
]
)

filegroup (
          name = "example_ws_html",
          srcs = ["examples/websocket/templates/ws.html"]
)

cc_binary(
    name = "example_ws",
    srcs = ["examples/websocket/example_ws.cpp"],
    data = [":example_ws_html"],
    deps = [":crow",
           "@boost//:algorithm",
           "@boost//:asio",
           "@boost//:optional",
]
)
