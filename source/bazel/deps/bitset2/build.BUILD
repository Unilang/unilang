package(default_visibility = ["//visibility:public"])

#build headers
hdrs = glob(
    include = [
        "detail/**/*.h",
        "detail/**/*.hpp",
        "bitset2.hpp",
    ],
    exclude = [
    ],
)

cc_library(
    name = "bitset",
    hdrs = hdrs,
    includes = [
        "detail",
    ],
)
