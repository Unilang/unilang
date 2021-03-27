def unilang_to_protobuf(name, deps = []):
    #the file names to use
    protobuf_target_name = name + "_protobuf"
    explicit_unilang_file = name + ".unilang"
    explicit_proto_file = name + ".proto"

    #converting hcp to hpp/cpp
    native.genrule(
        name = protobuf_target_name,
        srcs = [explicit_unilang_file],
        outs = [explicit_proto_file],
        tools = ["//code/programs/transcompilers/old_unilang/main:unilang-transcompiler"],
        cmd = """
    $(location //code/programs/transcompilers/old_unilang/main:unilang-transcompiler) --input_files $(SRCS) --dir $(@D) --exporter trevor --languages PROTOBUF --style normal --build-only
        """,
    )
