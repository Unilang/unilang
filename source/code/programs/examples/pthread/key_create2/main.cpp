#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUMTHREADS 4

pthread_key_t glob_var_key;

void do_something()
{
    //get thread specific data
    int* glob_spec_var = (int *)pthread_getspecific(glob_var_key);
    printf("Thread %d before mod value is %d\n", (unsigned int) pthread_self(), *glob_spec_var);
    *glob_spec_var += 1;
    printf("Thread %d after mod value is %d\n", (unsigned int) pthread_self(), *glob_spec_var);
}

void* thread_func(void *arg)
{
    int *p = (int *)malloc(sizeof(int));
    *p = 1;
    pthread_setspecific(glob_var_key, p);
    do_something();
    do_something();
    pthread_setspecific(glob_var_key, NULL);
    free(p);
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t threads[NUMTHREADS];
    int i;

    pthread_key_create(&glob_var_key,NULL);
    for (i=0; i < NUMTHREADS; i++)
        pthread_create(threads+i,NULL,thread_func,NULL);

    for (i=0; i < NUMTHREADS; i++)
        pthread_join(threads[i], NULL);

    return 0;
}