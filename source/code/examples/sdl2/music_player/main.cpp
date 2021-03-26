#include "code/utilities/peripheral/sound/music_player.hpp"
int main ( int argc, char* argv[] ) {
  
    auto music = Music_Player::Play("/usr/local/share/mario/main_theme.mp3",true);
    (void)music;
    while(true){}
    
    

  return 0;
}