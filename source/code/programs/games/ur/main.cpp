#include <string>
#include <iostream>
#include "code/programs/games/ur/assets/assets_loader.hpp"
#include "code/programs/games/ur/state/game_state_getter.hpp"
#include "code/programs/games/ur/core/frame_renderer.hpp"
#include "code/programs/games/ur/core/state_updater.hpp"
#include "code/utilities/graphics/sfml/game_loop.hpp"
#include "code/utilities/graphics/sfml/standard_sfml_game_loop.hpp"

int main()
{
    
    //get all the assets and game state
    auto state = Game_State_Getter::Get();
    auto assets = Assets_Loader::Load(state);
    
    
    Standard_Sfml_Game_Loop::Run(
    "Cats and Dogs",
    [&](sf::RenderWindow & window, sf::Time const& TimePerFrame){
        State_Updater::Run_Frame_Logic(window,TimePerFrame,state,assets);
    },
    [&](sf::RenderWindow & window){
        Frame_Renderer::Run_Frame_Render(window,state,assets);
    });

    return 0;
}


