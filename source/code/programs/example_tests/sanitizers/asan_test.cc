// https://clang.llvm.org/docs/AddressSanitizer.html#usage
int main(int argc, char **argv) {
    int *array = new int[100];
    delete[] array;
    return array[argc];  // BOOM
}
