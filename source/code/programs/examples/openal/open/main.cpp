#include <iostream>
#include <al.h>
#include <alc.h>


int main(){
    ALCdevice *device;

    device = alcOpenDevice(NULL);
    if (device){
        std::cout << "opened" << std::endl;
    }
    else {
        std::cout << "not opened" << std::endl;
        exit(0);
    }
}