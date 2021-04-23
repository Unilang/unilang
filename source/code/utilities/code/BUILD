package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/tree_hcp:string_tree_getter.bzl", "string_tree_getter")
load("//bazel/rules/tree_hcp:static_tree_structs.bzl", "static_tree_structs")
load("//bazel/rules/tree_hcp:string_tree_to_static_tree_parser.bzl", "string_tree_to_static_tree_parser")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")
load("//bazel/rules/tree_hcp:string_tree_default_references.bzl", "string_tree_default_references")
load("//bazel/rules/tree_hcp:static_tree_variants.bzl", "static_tree_variants")
load("//bazel/rules/tree_hcp:static_tree_pk_resolver.bzl", "static_tree_pk_resolver")

# a C++ function for getting the StringTree type
string_tree_getter(name = "concept")

# all of the C++ structs from the tree description
static_tree_structs(name = "concept")

# a C++ function for automatically turning StringTree into Code type
string_tree_to_static_tree_parser(name = "concept")

# creates a json file of tree element relationships (PK/FK, suggests potential variant types)
string_tree_default_references("concept_references")

static_tree_variants(
    references = "concept_references",
    tree = "concept",
)

static_tree_pk_resolver(
    references = "concept_references",
    tree = "concept",
)

hcp(
    name = "concept_tree_to_image",
    deps = [
        "//code/utilities/code:concept_string_tree_getter",
        "//code/utilities/data_structures/graphics/bitmap/premade:tree_button",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree:buildable_schema_face_tree_drawer",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree:string_tree_to_buildable_schema_faced_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_tree_label_drawer",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:positioned_button_face_tree",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:string_tree_to_buttoned_face_tree",
        "//code/utilities/data_structures/graphics/objects/label/style:default_label_styles",
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/fonts/bdf/complete/unilang:unilang_character_maps",
        "//code/utilities/graphics/cairo/render:cairo_render_settings",
        "//code/utilities/graphics/cairo/render:frame_renderer",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/personal/hosting:hosting_repo",
        "//code/utilities/program/wrappers/convert:image_transparent",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/tree/converters:tree_full_paths_getter",
        "//code/utilities/types/vectors/observers:lib",
        "@tree",
    ],
)

# how the data is to be thought of and understood.
# this also effects how the code is generated.
# every UniLang file represents one of the following:
# It's either:
# GLOBAL: global collection of data and functions
# SUM_TYPE: a union/variant/sum type with possible methods and other miscellaneous data (typedefs/enums/inlined includes/etc)
# PRODUCT_TYPE: a collection of data inside an object with possible methods and other miscellaneous data (typedefs/enums/inlined includes/etc)
enum_cpp(
    name = "code_type",
    values = [
        "global",
        "sum_type",
        "product_type",
    ],
)

enum_cpp(
    name = "class_access",
    values = [
        "public",
        "protected",
        "private",
    ],
)

enum_cpp(
    name = "import_type",
    values = [
        "system",
        "local",
    ],
)

enum_cpp(
    name = "storage_specifier",
    values = [
        "static",
        "extern",
        "none",
    ],
)

enum_cpp(
    name = "mutability",
    values = [
        "immutable",
        "mutable",
    ],
)
