#include <iostream>
#include <cpuinfo.h>

int main(){
    cpuinfo_initialize();
    printf("Running on %s CPU\n", cpuinfo_get_package(0)->name);
}