package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "two_d_coordinate_dimension",
    values = [
        "x",
        "y",
    ],
)

enum_cpp(
    name = "optional_two_d_coordinate_dimension",
    values = [
        "x",
        "y",
        "none",
    ],
)

enum_cpp(
    name = "compass_direction",
    values = [
        "north",
        "west",
        "south",
        "east",
    ],
)

enum_cpp(
    name = "compass_direction_diagnonal",
    values = [
        "north",
        "west",
        "south",
        "east",
        "north_west",
        "north_east",
        "south_west",
        "south_east",
    ],
)

enum_cpp(
    name = "optional_compass_direction",
    values = [
        "north",
        "west",
        "south",
        "east",
        "none",
    ],
)

#how to index into containers (treating the values as further indexes)
enum_cpp(
    name = "index_mode",
    values = [
        "position",
        "immediate",
        "relative",
    ],
)

enum_cpp(
    name = "headedness",
    values = [
        "left",
        "right",
    ],
)

enum_cpp(
    name = "concurrency",
    values = [
        "sequential",
        "parallel",
    ],
)

enum_cpp(
    name = "halting_problem_result",
    values = [
        "halts",
        "does_not_halt",
    ],
)

enum_cpp(
    name = "string_sort_strategy",
    values = [
        "alphabetize",
        "alphabetize_and_sort_by_length",
    ],
)

#useful for directed graphs
enum_cpp(
    name = "arrow_direction",
    values = [
        "start",
        "end",
        "both",
        "none",
    ],
)

#every feature / pull request should have kind of a life cycle on how it came to be
#something like that
enum_cpp(
    name = "feature_lifecycle",
    values = [
        "discover",
        "design",
        "implementation",
        "testing",
        "documentation",
        "maintain",
    ],
)

enum_cpp(
    name = "playing_card",
    values = [
        "card_1_clover",
        "card_1_diamond",
        "card_1_heart",
        "card_1_spade",
        "card_2_clover",
        "card_2_diamond",
        "card_2_heart",
        "card_2_spade",
        "card_3_clover",
        "card_3_diamond",
        "card_3_heart",
        "card_3_spade",
        "card_4_clover",
        "card_4_diamond",
        "card_4_heart",
        "card_4_spade",
        "card_5_clover",
        "card_5_diamond",
        "card_5_heart",
        "card_5_spade",
        "card_6_clover",
        "card_6_diamond",
        "card_6_heart",
        "card_6_spade",
        "card_7_clover",
        "card_7_diamond",
        "card_7_heart",
        "card_7_spade",
        "card_8_clover",
        "card_8_diamond",
        "card_8_heart",
        "card_8_spade",
        "card_9_clover",
        "card_9_diamond",
        "card_9_heart",
        "card_9_spade",
        "card_10_clover",
        "card_10_diamond",
        "card_10_heart",
        "card_10_spade",
        "card_11_clover",
        "card_11_diamond",
        "card_11_heart",
        "card_11_spade",
        "card_12_clover",
        "card_12_diamond",
        "card_12_heart",
        "card_12_spade",
        "card_13_clover",
        "card_13_diamond",
        "card_13_heart",
        "card_13_spade",
    ],
)
