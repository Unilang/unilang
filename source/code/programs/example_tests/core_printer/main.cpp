#include <thread>
#include <memory>
#include <iostream>
int main(){
    int threadNumbers = std::thread::hardware_concurrency();
    std::cout << "observed cores: " << threadNumbers << std::endl;
}