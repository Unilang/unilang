// https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html#usage
int main(int argc, char **argv) {
    int k = 0x7fffffff;
    k += argc;
    return 0;
}
