#Clang compiler warnings to use by other rules

#Linker warnings:
#"-Wl,--warn-execstack",
#"-Wl,--detect-odr-violations",

WARNING_FLAGS = [
    "-Weverything",
    "-Wall",
    "-Wextra",
    "-Wunused-but-set-parameter",
    "-Wformat-security",
    "-Wstrict-null-sentinel",
    "-Wno-c++98-compat",
    "-Wno-c++98-compat-pedantic",
    "-Wno-disabled-macro-expansion",

    # every float is exactly representable as a double. On some architectures
    # there is a reason to care about floats implicitly promoted to doubles,
    # but not on x86.
    "-Wno-double-promotion",
    "-Wno-float-equal",
    "-Wno-padded",

    # This is a warning that a move would not have been applied on old compilers
    # https://reviews.llvm.org/D43322
    "-Wno-return-std-move-in-c++11",

    # proto3 generates headers which violate this warning and bazel includes
    # the generated headers with iquote not isystem. Otherwise, this would be
    # a legit warning.
    "-Wno-zero-as-null-pointer-constant",

    # This requires that all polymorphic classes have at least one non-inline
    # virtual method declaration so the compiler can give the class's vtable
    # a single home.  While that's a good practice, it means header-only libs
    # can't have polymorphism since header-only implies fully inlined.  This
    # warning is also somewhat hypocritical because it appears that templates
    # are exempt.  That is reasonable (having non-inline template functions
    # means tricky explicit instantiation) but does mean this "problem" will
    # exist in the system even with the diagnostic so this doesn't seem to be
    # worth the loss of having header only layouts
    "-Wno-weak-vtables",

    # clang seems to not understand quite a few doc commands, so add them in
    "-fcomment-block-commands=file",

    # clang has a problem with doing something like @file \n @ingroup because
    # the @file doesn't have text (which is valid - it means 'this file').
    "-Wno-documentation",

    # Abseil is a native bazel library that is found through quote includes
    # and is not -Wsign-conversion clean in its headers.
    "--system-header-prefix=absl/",
    "--system-header-prefix=third_party/",
    "--system-header-prefix=tensorflow/",

    # https://bugs.llvm.org/show_bug.cgi?id=18733
    "-Wno-weak-template-vtables",

    # This allows -Wthread-safety-* to be used with libc++ synchronization primitives.
    "-D_LIBCPP_ENABLE_THREAD_SAFETY_ANNOTATIONS",

    # These are experimental features that require changes to code for every user of std::mutex.
    "-Wno-thread-safety-negative",
    "-Wno-thread-safety-beta",

    # We have macros that unconditionally pack, even if it's not needed.
    "-Wno-packed",

    # This complains about things like `std::lock_guard guard(mutex);`
    "-Wno-ctad-maybe-unsupported",

    # Disabled just for the clang 10 release. This will need to be cleaned up later
    "-Wno-enum-enum-conversion",

    # This warning triggers a lot. At some point, we will want to burn down our
    # uses of it.
    "-Wno-implicit-int-float-conversion",

    # In C++20 macros with zero(empty) variadic arguments are explicitly supported.
    "-Wno-gnu-zero-variadic-macro-arguments",

    # We're compiling for C++20 so the c++20-compat warning doesn't apply.
    # These are warnings about code that is incompatible with C++ standards before C++20.
    "-Wno-c++20-compat",
    "-Wno-c++20-compat-pedantic",
]

TEST_WARNING_FLAGS = WARNING_FLAGS + [
    # Google Test requires the use of global constructors to register tests, which
    # is fine in the test context.
    "-Wno-global-constructors",

    # Google Test requires the use of exit time destructors to register tests, which
    # is fine in the test context.
    "-Wno-exit-time-destructors",

    # gtest SCOPED_TRACE uses a class marked "GTEST_ATTRIBUTE_UNUSED_" because the
    # instance var isn't used (beyond cstr/dstr side effects).  Apparently clang
    # don't consider that unused so warns the attribute is unnecessary.
    "-Wno-used-but-marked-unused",

    # the gtest TYPED_TEST macro causes this warning
    "-Wno-missing-variable-declarations",

    # GTest's parametric tests make use of variadic expansion without initial arguments...
    "-Wno-gnu-zero-variadic-macro-arguments",
]

BENCHMARK_WARNING_FLAGS = WARNING_FLAGS + [
    # Google Benchmark requires the use of global constructors to register
    # tests, which is fine in the benchmarking context.
    "-Wno-global-constructors",
]
