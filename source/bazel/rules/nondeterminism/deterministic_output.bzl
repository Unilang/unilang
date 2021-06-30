def deterministic_output(name):
    target_name = name
    outfile = name + "_deterministic.txt"

    native.genrule(
        name = target_name,
        srcs = [],
        outs = [outfile],
        cmd = """
              echo 'hello world' > $(OUTS)
              """,
    )
