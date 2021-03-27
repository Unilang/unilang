load("//bazel/rules/cpp:object.bzl", "cpp_object")

#using the original hcp compiler built from raw c++
def bootstrap_hcp(name, deps = []):
    #the file names to use
    hcp_target_name = name + "_hcp"
    explicit_hcp_file = name + ".hcp"
    explicit_cpp_file = name + ".cpp"
    explicit_hpp_file = name + ".hpp"

    #converting hcp to hpp/cpp
    native.genrule(
        name = hcp_target_name,
        srcs = [explicit_hcp_file],
        outs = [explicit_cpp_file, explicit_hpp_file],
        tools = ["//code/programs/transcompilers/hcp-compiler/bootstrap:hcp-compiler"],
        cmd = """
    $(location //code/programs/transcompilers/hcp-compiler/bootstrap:hcp-compiler) $(SRCS) -o $(@D) --no-utility-functions
                 """,
    )

    #compiling hpp/cpp
    cpp_object(name, deps)
