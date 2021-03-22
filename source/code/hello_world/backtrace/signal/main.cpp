#include <iostream>
#include "code/utilities/program/common_actions/signals/all_signal_setter.hpp"
#include "code/utilities/program/common_actions/backtrace/backtrace.hpp"
#include "code/utilities/program/common_actions/backtrace/exceptions.hpp"

void func1();
void func2();
void func3();


void func1(){
    func2();
}

void func2(){
    
    func3();
}

void func3(){
    std::cout << "sdfsdf" << std::endl;

    //induce a segfault crash
    int* x = (int*) -1;
    int y = *x;
}

int main(){
    Bind_All_Signals_To_Handler([](int i){
        std::string stackTrace = get_stacktrace();
        std::cout << stackTrace << std::endl;
        exit(-1);
    });
    

        func1();
}