#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>


Mix_Music* play(){
   //Initialize SDL
    if( SDL_Init( SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        exit(1);
    }
    
     //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        exit(1);
    }
    
    int result = 0;
    int flags = MIX_INIT_MP3;
    if (flags != (result = Mix_Init(flags))) {
        printf("Could not initialize mixer (result: %d).\n", result);
        exit(1);
    }
    
    Mix_Music *music = Mix_LoadMUS("/usr/local/share/mario/main_theme.mp3");
    if (!music){
        std::cerr << "error loading music" << std::endl;
        exit(1);
    }
    
    Mix_PlayMusic(music, 1);
    return music;
    
}
int main ( int argc, char* argv[] ) {
  
    play();
    while(true){}
    
    

  return 0;
}