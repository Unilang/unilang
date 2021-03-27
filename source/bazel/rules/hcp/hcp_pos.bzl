load("//bazel/rules/cpp:object.bzl", "cpp_object")

#using the boot-strapped hcp compiler built from hcp files
def hcp_pos(name, deps = [], data = []):
    #the file names to use
    hcp_target_name = name + "_pos_hcp"
    explicit_hcp_file = name + ".hcp"
    explicit_cpp_file = "positioned_" + name + ".cpp"
    explicit_hpp_file = "positioned_" + name + ".hpp"

    #converting hcp to hpp/cpp
    native.genrule(
        name = hcp_target_name,
        srcs = [explicit_hcp_file],
        outs = [explicit_cpp_file, explicit_hpp_file],
        tools = ["//code/programs/transcompilers/hcp-compiler/official_pos:hcp-compiler"],
        cmd = "$(location //code/programs/transcompilers/hcp-compiler/official_pos:hcp-compiler) $(SRCS) -o $(@D)",
    )

    #compiling hpp/cpp
    real_deps = list(deps)
    real_deps += ["@boost//:serialization"]
    real_deps += ["@nlohmann_json//:nlohmann_json"]
    real_deps += ["//code/utilities/data_structures/position:position"]
    real_deps += ["//code/utilities/formats/json/overloads:tree_json_converters"]
    cpp_object("positioned_" + name, real_deps, data)
