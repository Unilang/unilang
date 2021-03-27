#include <iostream>
#include "PoppyDebugTools.h"

void func1();
void func2();
void func3();


void func1(){
    STACK
    //func2();
    func3();
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
    try{
        func1();
    }
    catch(...){
    
        std::string stackTrace = Stack::GetTraceString();
        std::cout << stackTrace << std::endl;
    }
}