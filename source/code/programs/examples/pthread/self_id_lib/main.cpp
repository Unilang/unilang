#include <stdio.h>
#include "lib.hpp"

int main(void)
{
    auto tid = get_self_id();
    printf("TID = %lu\n", tid);

return 0;
}