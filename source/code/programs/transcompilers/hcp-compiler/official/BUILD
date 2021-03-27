package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:bootstrap_hcp.bzl", "bootstrap_hcp")

bootstrap_hcp(
    name = "class_structure",
)

bootstrap_hcp(
    name = "class_structure_creator",
    deps = [
        "class_structure",
        "header_validator",
        "//code/programs/transcompilers/hcp-compiler/official/structure_state:lib",
        "//code/programs/transcompilers/hcp-compiler/official/unicode_parser_symbols:lib",
        "//code/utilities/language_basic/multiple_relational_comparing:lib",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/char:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/stripping:lib",
    ],
)

bootstrap_hcp(
    name = "global_structure_creator",
    deps = [
        "class_structure",
        "header_validator",
        "//code/programs/transcompilers/hcp-compiler/official/structure_state:lib",
        "//code/programs/transcompilers/hcp-compiler/official/unicode_parser_symbols:lib",
        "//code/utilities/language_basic/multiple_relational_comparing:lib",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/char:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/stripping:lib",
    ],
)

bootstrap_hcp(
    name = "header_validator",
    deps = [
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/char:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/wstrings/transformers/other:lib",
    ],
)

bootstrap_hcp(
    name = "hcp_class_parser",
    deps = [
        "class_structure",
        "class_structure_creator",
    ],
)

bootstrap_hcp(
    name = "hcp_global_parser",
    deps = [
        "class_structure",
        "global_structure_creator",
    ],
)

bootstrap_hcp(
    name = "hcp_parser",
    deps = [
        "class_structure",
        "hcp_class_parser",
        "hcp_global_parser",
        "//code/utilities/program/common_actions/exits:lib",
    ],
)

bootstrap_hcp(
    name = "global_compiler",
    deps = [
        "class_structure",
        "include_file_printer",
        "//code/programs/transcompilers/hcp-compiler/bootstrap/core/structure:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/wstrings/transformers/other:lib",
        "//code/utilities/types/wstrings/transformers/trimming:lib",
    ],
)

bootstrap_hcp(
    name = "class_compiler",
    deps = [
        "class_structure",
        "include_file_printer",
        "//code/programs/transcompilers/hcp-compiler/bootstrap/core/structure:lib",
        "//code/programs/transcompilers/shared:json_gen",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/wstrings/transformers/other:lib",
        "//code/utilities/types/wstrings/transformers/trimming:lib",
    ],
)

bootstrap_hcp(
    name = "hcp_compiler",
    deps = [
        "class_compiler",
        "global_compiler",
        "//code/utilities/program/common_actions/exits:lib",
    ],
)

bootstrap_hcp(
    name = "root_settings",
)

bootstrap_hcp(
    name = "root_settings_getter",
    deps = ["root_settings"],
)

bootstrap_hcp(
    name = "task_executer",
    deps = [
        "//code/programs/transcompilers/hcp-compiler/official:bazel_deps_printer",
        "//code/programs/transcompilers/hcp-compiler/official:file_name_checker",
        "//code/programs/transcompilers/hcp-compiler/official:hcp_compiler",
        "//code/programs/transcompilers/hcp-compiler/official:hcp_parser",
        "//code/programs/transcompilers/hcp-compiler/official/program_options:lib",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/wstrings/transformers/other:lib",
    ],
)

bootstrap_hcp(
    name = "file_name_checker",
    deps = [
        "hcp_compiler",
        "hcp_parser",
        "//code/programs/transcompilers/hcp-compiler/official/program_options:lib",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/wstrings/transformers/other:lib",
    ],
)

bootstrap_hcp(
    name = "bazel_deps_printer",
    deps = [
        "hcp_compiler",
        "hcp_parser",
        "//code/programs/transcompilers/hcp-compiler/official/program_options:lib",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/wstrings/transformers/other:lib",
    ],
)

bootstrap_hcp(
    name = "include_file_printer",
    deps = [
        ":class_structure",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/wstrings/transformers/other:lib",
        "//code/utilities/types/wstrings/transformers/trimming:lib",
    ],
)

cc_binary(
    name = "hcp-compiler",
    srcs = ["main.cpp"],
    deps = [
        "task_executer",
        "//code/programs/transcompilers/hcp-compiler/official/program_options:lib",
        "//code/utilities/program/common_actions/locale:lib",
    ],
)
