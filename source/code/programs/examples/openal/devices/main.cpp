#include <iostream>
#include <al.h>
#include <alc.h>

static void list_audio_devices(const ALCchar *devices)
{
        const ALCchar *device = devices, *next = devices + 1;
        size_t len = 0;

        fprintf(stdout, "Devices list:\n");
        fprintf(stdout, "----------\n");
        while (device && *device != '\0' && next && *next != '\0') {
                fprintf(stdout, "%s\n", device);
                len = strlen(device);
                device += (len + 1);
                next += (len + 2);
        }
        fprintf(stdout, "----------\n");
}

int main(){

    ALboolean enumeration;
    enumeration = alcIsExtensionPresent(NULL, "ALC_ENUMERATION_EXT");
    if (enumeration == AL_FALSE){
            std::cout << "enumeration not supported" << std::endl;
            exit(0);
    }
    else{
            std::cout << "enumeration supported" << std::endl;
    }
    
    list_audio_devices(alcGetString(NULL, ALC_DEVICE_SPECIFIER));

}