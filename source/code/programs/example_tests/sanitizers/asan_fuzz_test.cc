// https://llvm.org/docs/LibFuzzer.html#toy-example
#include <stddef.h>
#include <stdint.h>
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    if (size > 0 && data[0] == 'H')
        if (size > 1 && data[1] == 'I')
            if (size > 2 && data[2] == '!') __builtin_trap();
    return 0;
}
