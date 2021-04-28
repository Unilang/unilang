#pragma once
#include <chrono>

template <typename Fun>
double Profile_Function_Ms(Fun fun)
{
    auto start = std::chrono::high_resolution_clock::now(); 
    fun();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    return duration.count();
}