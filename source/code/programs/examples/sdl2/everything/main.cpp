#include <SDL.h>
#include <stdio.h>
void init ( ) {
   if ( SDL_Init ( SDL_INIT_EVERYTHING ) < 0 ) { /* Handle problem */
    fprintf ( stderr, "%s\n", SDL_GetError ( ) );
    SDL_Window* window = SDL_CreateWindow ( "SDL2 Test",              //
                                      SDL_WINDOWPOS_UNDEFINED,  //
                                      SDL_WINDOWPOS_UNDEFINED,  //
                                      640,                      //
                                      480,                      //
                                      SDL_RENDERER_ACCELERATED );
  if ( window == NULL ) { /* Handle problem */
    fprintf ( stderr, "%s\n", SDL_GetError ( ) );
    SDL_Quit ( );
  }
  }
}

int main ( int argc, char* argv[] ) {
  init ( );
  SDL_Delay(3000);
  SDL_Quit ( );

  return 0;
}