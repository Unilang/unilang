load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp.bzl", "hcp")

def static_tree_variants(tree, references):
    #the file names to use
    target_name = tree + "_static_tree_variants_build"
    in_file1 = tree + ".dat"
    in_file2 = references + ".json"
    outfile1 = tree + "_static_tree_variants.hpp"
    outfile2 = tree + "_static_tree_variants.cpp"

    #create the tree struct source files
    native.genrule(
        name = target_name,
        srcs = [in_file1, in_file2],
        outs = [outfile1, outfile2],
        tools = ["//code/programs/transcompilers/tree_hcp/static_tree_variants:static_tree_variants"],
        cmd = "$(location //code/programs/transcompilers/tree_hcp/static_tree_variants:static_tree_variants) -i $(SRCS) --name {}  -o $(@D)".format(tree + "_static_tree_variants"),
    )

    #compile cpp object
    real_deps = []
    real_deps += ["@tree"]
    real_deps += ["@boost//:serialization"]
    real_deps += ["@nlohmann_json//:nlohmann_json"]
    real_deps += ["//code/utilities/code:concept_static_tree_structs"]
    real_deps += ["//code/utilities/formats/json/overloads:tree_json_converters"]
    cpp_object(tree + "_static_tree_variants", real_deps)
