#include <thread>
#include <iostream>

#include <GL/gl.h>
#include <GL/glx.h>
#include "code/utilities/graphics/x11/main_state/setup_display_settings.hpp"
#include "code/utilities/graphics/x11/main_state/x11_main_state_creator.hpp"
#include "code/utilities/graphics/glx/x11_to_opengl_binder.hpp"

Main_X11_State setup() {

    Setup_Display_Settings settings;
    settings.window.use_root = false;
    settings.window.pos.x = 0;
    settings.window.pos.y = 0;
    settings.window.dim.width = 860;
    settings.window.dim.height = 640;
    settings.window.border_width = 1;
    settings.window.border = 0;
    settings.window.background = 0;
    auto x11 = X11_Main_State_Creator::Create(settings);
    
    return x11;
}

int main() {

    auto x11 = setup();
    X11_To_Opengl_Binder::Bind(x11);

    using namespace std::chrono_literals;
    float r = 0;
    while (true) {
        glClearColor(r, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glXSwapBuffers(x11.d, x11.root);
        std::this_thread::sleep_for(1s);
        r += 0.1f;
        if (r > 1) r = 0;
    }

}