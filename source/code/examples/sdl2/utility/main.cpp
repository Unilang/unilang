#include <float.h>
#include "code/utilities/graphics/sdl/sdl_init_settings.hpp"
#include "code/utilities/graphics/sdl/sdl_window_creator.hpp"
#include "code/utilities/graphics/sdl/sdl_initializer.hpp"

int main()
{

    //how to init the SDL window
    Sdl_Init_Settings s;
    s.main_window.title = "hello world";
    
    Sdl_Initializer::Initialize();
    auto window = Sdl_Window_Creator::Create(s.main_window);
    while (true){}
}
