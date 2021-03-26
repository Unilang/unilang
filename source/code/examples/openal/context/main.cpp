#include <iostream>
#include <al.h>
#include <alc.h>


int main(){

    // open device
    ALCdevice* device = alcOpenDevice(NULL);
    if (device){
        std::cout << "opened" << std::endl;
    }
    else {
        std::cout << "not opened" << std::endl;
        exit(0);
    }
    
    
    //create context
    ALCcontext* context = alcCreateContext(device, NULL);
    if (alcMakeContextCurrent(context)){
        std::cout << "context created" << std::endl;
    }
    else{
        std::cout << "failed to make context current" << std::endl;
        exit(0);
    }
    
    // test for errors
    ALCenum error = alGetError();
    if (error == AL_NO_ERROR){
        std::cout << "no errors" << std::endl;
    }
    else{
        std::cout << "something wrong happened" << std::endl;
        exit(0);
    }
    
    //cleanup
    alcDestroyContext(context);
    alcCloseDevice(device);
}