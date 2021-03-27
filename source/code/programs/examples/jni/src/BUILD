load("@rules_java//java:defs.bzl", "java_binary")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "main-jni-lib",
    srcs = [
        "Main.cc",
        "Main.h",
    ],
    hdrs = [
        "@bazel_tools//tools/jdk:jni_header",
        "@bazel_tools//tools/jdk:jni_md_header-linux",
    ],
    # deps = [
    #     "@bazel_tools//tools/jdk:jni_header",
    #     "@bazel_tools//tools/jdk:jni_md_header-linux",
    # ],
    includes = [
        "external/bazel_tools/tools/jdk/include",
        "external/bazel_tools/tools/jdk/include/linux",
    ],
    deps = [":jni"],
    #copts = [
    #"-isystem","external/bazel_tools/tools/jdk/include",
    #"-isystem","external/bazel_tools/tools/jdk/include/linux",
    #"-isystem","external/local_jdk/include",
    #"-isystem","bazel-out/k8-fastbuild/bin/external/bazel_tools/tools/jdk/include",
    #"-isystem","bazel-out/k8-fastbuild/bin/external/bazel_tools/tools/jdk/include/linux"],
    alwayslink = True,
    #strip_include_prefix = "code/programs/examples/jni/src/",
)

cc_library(
    name = "jni",
    hdrs = [
        ":jni.h",
        ":jni_md.h",
    ],
    # The includes line is necessary to expose these as system headers. Be
    # careful not to overpopulate this directory.
    includes = ["."],
)

# Hacky workaround to expose <jni.h> headers in cc_library rules. The JNI
# headers are magically exposed to genrules, so we export the headers of
# interest from those genrules. See
# https://github.com/tensorflow/tensorflow/blob/5dfbeab6c01a5919324a94c0092d34e6be218c3d/tensorflow/java/src/main/native/BUILD#L51
genrule(
    name = "copy_jni_h",
    srcs = ["@bazel_tools//tools/jdk:jni_header"],
    outs = ["jni.h"],
    cmd = "cp -f $< $@",
)

genrule(
    name = "copy_jni_md_h",
    srcs = select({
        "//conditions:default": ["@bazel_tools//tools/jdk:jni_md_header-linux"],
    }),
    outs = ["jni_md.h"],
    cmd = "cp -f $< $@",
)

cc_binary(
    name = "libmain-jni.so",
    linkshared = True,
    deps = [":main-jni-lib"],
)

java_binary(
    name = "Main",
    srcs = ["Main.java"],
    #resources = [ ":libmain-jni.so" ],
    #runtime_deps = [ ":libmain-jni.so" ],
    #use_testrunner = False,
    #deploy_env = [ ":libmain-jni.so" ],
    #create_executable = True,
    #deps = [ ":libmain-jni.so" ],
    data = [":libmain-jni.so"],
    #javacopts = [ "-Djava.library.path=example" ],

    #works only if I do a full path.  relative fron runfiles doesn't work either.
    #https://github.com/bazelbuild/bazel/issues/10754
    #https://github.com/bazelbuild/bazel/issues/6958
    jvm_flags = ["-Djava.library.path=."],
    main_class = "Main",
)
