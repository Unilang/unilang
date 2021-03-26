#include <iostream>
#include "code/utilities/program/common_actions/signals/all_signal_setter.hpp"
#include "code/utilities/program/common_actions/backtrace/backtrace.hpp"
#include "code/utilities/program/common_actions/backtrace/exceptions.hpp"

void func1();
void func2();
void func3();


void func1(){
    //func2();
    func3();
}

void func2(){

    //induce a segfault crash
    int* x = (int*) -1;
    int y = *x;
}

void func3(){
    throw std::runtime_error("error");
}

int main(){
    
    try{

        func1();
    }
    catch(std::exception e){
        std::cout << get_symbolized_stacktrace(e) << std::endl;
    }
}