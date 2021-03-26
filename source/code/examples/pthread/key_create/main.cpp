#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_key_t buffer_key;

void buffer_key_destruct( void *value )
{
    free( value );
    pthread_setspecific( buffer_key, NULL );
}

char *lookup( void )
{
    char *string;

    string = (char *)pthread_getspecific( buffer_key );
    if( string == NULL ) {
        string = (char *) malloc( 32 );
        sprintf( string, "This is thread %d\n", pthread_self() );      
        pthread_setspecific( buffer_key, (void *)string );
    }

    return( string );
}

void *function( void *arg )
{
    while( 1 ) {
        puts( lookup() );
    }

    return( 0 );
}

int main( void )
{
    pthread_key_create( &buffer_key,
                        &buffer_key_destruct );
    
    pthread_t thread;
    pthread_create(&thread, NULL, &function, NULL );

    /* Let the threads run for 60 seconds. */
    sleep( 60 );
    
    return EXIT_SUCCESS;
}
