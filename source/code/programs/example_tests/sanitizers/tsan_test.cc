// https://clang.llvm.org/docs/ThreadSanitizer.html#usage
#include <pthread.h>
int Global;
void *Thread1(void *x) {
    Global = 42;
    return x;
}
int main() {
    pthread_t t;
    Global = 41;
    pthread_create(&t, NULL, Thread1, NULL);
    Global = 43;
    pthread_join(t, NULL);
    return Global - Global;
}
