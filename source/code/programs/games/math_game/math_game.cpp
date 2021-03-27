#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include "code/utilities/peripheral/keyboard/joycons/joycon_state_getter.hpp"
#include "code/utilities/formats/json/converters/lib.hpp"
#include "code/programs/games/math_game/assets/assets_loader.hpp"
#include "code/programs/games/math_game/state/game_state.hpp"
#include "code/programs/games/math_game/state/game_state_getter.hpp"
#include "code/programs/games/math_game/core/frame_renderer.hpp"
#include "code/programs/games/math_game/core/state_updater.hpp"
#include "code/utilities/graphics/sfml/game_loop.hpp"
#include "code/utilities/graphics/sfml/standard_sfml_game_loop.hpp"

int main()
{
    
    //get all the assets and game state
    auto assets = Assets_Loader::Load();
    auto state = Game_State_Getter::Get();
    
    Standard_Sfml_Game_Loop::Run(
    "Math Game",
    [&](sf::RenderWindow & window, sf::Time const& TimePerFrame){
        State_Updater::Run_Frame_Logic(window,TimePerFrame,state,assets);
    },
    [&](sf::RenderWindow & window){
        Frame_Renderer::Run_Frame_Render(window,state,assets);
    });

    return 0;
}


