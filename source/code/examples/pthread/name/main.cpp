// #define _GNU_SOURCE is needed for the resolution of the following warnings
//warning: implicit declaration of function ‘pthread_setname_np’ [-Wimplicit-function-declaration]
//warning: implicit declaration of function ‘pthread_getname_np’ [-Wimplicit-function-declaration]
//#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <asm/errno.h>
#include <errno.h>
// #include <stdlib.h> is needed for the resolution of EXIT_SUCCESS
#include <stdlib.h>
 
//The thread name is a meaningful C language string, whose length is restricted to 16 characters, including the terminating null byte.
#define MAX_LENGTH_PTHREAD_NAME (16) 
 
struct thread_info_t
{
    // Used to identify a thread.
    pthread_t thread_id;
};
 
// This is the thread that will be called by pthread_create() and it will be executed by the new thread.
void *self_named_thread(void *data)
{
    // We know that the input data pointer is pointing to a thread_info_t so we are casting it to the right type.
    struct thread_info_t *thread_info = (struct thread_info_t *) data;
 
    const int setname_rv = pthread_setname_np(thread_info->thread_id, "Tom Hanks");
    if (setname_rv)
    {
        errno = setname_rv;
        perror("Could not set pthread name");
    }
 
    char thread_name[MAX_LENGTH_PTHREAD_NAME];
    const int getname_rv = pthread_getname_np(thread_info->thread_id, thread_name, MAX_LENGTH_PTHREAD_NAME);
    if (getname_rv)
    {
        errno = getname_rv;
        perror("Could not get pthread name");
    }
    //This function always succeeds, returning the calling thread's ID.
    const pthread_t tid = pthread_self();
    //Usually pthread_t is defined as follows:
    //typedef unsigned long int pthread_t;
    //so we print pthread_t as an unsigned long int
    fprintf(stdout, "I am thread with ID '%lu', my name is '%s' and I gave me my name by myself\n", tid, thread_name );
 
    return NULL;
}
 
int main()
{
    struct thread_info_t thread_info;
 
    const int create_rv = pthread_create(&(thread_info.thread_id), NULL, &self_named_thread, (void *) &thread_info);
    if (create_rv)
    {
        errno = create_rv;
        perror("Could not create thread");
        return EXIT_FAILURE;
    }
    // The pthread_join() function suspends execution of the calling thread until the target thread terminates, unless the target thread has already terminated.
    const int join_rv = pthread_join(thread_info.thread_id, NULL);
    if (join_rv)
    {
        errno = create_rv;
        perror("Could not join thread");
    }
    return EXIT_SUCCESS;
}