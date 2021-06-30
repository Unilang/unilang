def create_file_with_randomness(name):
    target_name = name
    outfile = name + "_random.txt"

    native.genrule(
        name = target_name,
        srcs = [],
        outs = [outfile],
        cmd = """
              echo $$RANDOM > $(OUTS)
              """,
    )
