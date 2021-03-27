load("//bazel/rules/cpp:gtest.bzl", "gtest")

package(
    default_visibility = ["//visibility:public"],
)

# no class (int)
gtest(
    name = "boost_non_class_int",
    deps = ["@boost//:serialization"],
)

gtest(
    name = "cereal_non_class_int",
    deps = ["@cereal//:main"],
)

# class (int)
gtest(
    name = "boost_class_int_intrusive",
    deps = ["@boost//:serialization"],
)

gtest(
    name = "boost_class_int_nonintrusive",
    deps = ["@boost//:serialization"],
)

gtest(
    name = "cereal_class_int_intrusive",
    deps = ["@cereal//:main"],
)

gtest(
    name = "cereal_class_int_nonintrusive",
    deps = ["@cereal//:main"],
)

gtest(
    name = "nlohmann_json_class_int_nonintrusive",
    deps = ["@nlohmann_json"],
)
