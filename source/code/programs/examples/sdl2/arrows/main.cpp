#include <SDL.h>
#include <iostream>

int main()
{
    
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
    
  SDL_Window* window = NULL;
  SDL_Surface* screenSurface = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
    return 1;
  }
  window = SDL_CreateWindow(
                "hello_sdl2",
                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH, SCREEN_HEIGHT,
                SDL_WINDOW_SHOWN
                );
  if (window == NULL) {
    fprintf(stderr, "could not create window: %s\n", SDL_GetError());
    return 1;
  }
  screenSurface = SDL_GetWindowSurface(window);
  SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
  SDL_UpdateWindowSurface(window);
  
  
    while (true){
        
        SDL_Event event;

        SDL_PollEvent(&event);
        if(event.type == SDL_KEYDOWN)
        {
            // Move centerpoint of rotation for one of the trees:
            switch(event.key.keysym.sym)
            {
                case SDLK_UP:
                    std::cout << "up" << std::endl;
                    break;
                case SDLK_DOWN:
                    std::cout << "down" << std::endl;
                    break;
                case SDLK_LEFT:
                    std::cout << "left" << std::endl;
                    break;
                case SDLK_RIGHT:
                    std::cout << "right" << std::endl;
                    break;
                case SDLK_ESCAPE:
                    std::cout << "esc" << std::endl;
                    return 0;
                default:
                    break;
            }
        }
    }

    return 0;
}