#include <iostream>
#include "PoppyDebugTools.h"
#include "code/utilities/program/common_actions/signals/all_signal_setter.hpp"

void func1();
void func2();
void func3();


void func1(){
    STACK
    func2();
    //func3();
}

void func2(){
    STACK

    //induce a segfault crash
    int* x = (int*) -1;
    int y = *x;
}

void func3(){
    STACK
    throw new std::runtime_error("error");
}

int main(){
    Bind_All_Signals_To_Handler([](int i){
        std::string stackTrace = Stack::GetTraceString();
        std::cout << stackTrace << std::endl;
        exit(-1);
    });

        func1();
}