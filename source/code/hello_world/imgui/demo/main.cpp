#include <float.h>
#include "code/utilities/graphics/imgui/loop/mechanics.hpp"
#include "code/utilities/graphics/sdl/sdl_init_settings.hpp"

int main()
{

    //how to init the SDL window
    Sdl_Init_Settings s;
    s.main_window.title = "hello world";
    
    //bind and run ImGui with SDL
    auto before = [](){};
    auto logic = [&](SDL_Window* window){};
    auto during = [](SDL_Window* window){
       bool flag = true;
       ImGui::ShowDemoWindow(&flag);
    };
    return Mechanics::render_each_frame(s,before,logic,during);
}