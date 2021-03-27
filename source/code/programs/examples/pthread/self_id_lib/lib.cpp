#include "lib.hpp"
#include <pthread.h>

unsigned long get_self_id(){
    return pthread_self();
}