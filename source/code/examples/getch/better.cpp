#include "code/utilities/ncurses/scoped_getch.hpp"
#include "getch/include/ch.hpp"
#include <iostream>

int main(){
    
    
    t_key keys[] = {
      {(char *)"[A", K_UP},
      {(char *)"[B", K_DOWN},
      {(char *)"[D", K_LEFT},
      {(char *)"[C", K_RIGHT},
      {NULL, K_UNK},
    };
    
    ScopedGetch getch_guard{};
    while(true){
        auto key = ch_get(keys);
        switch(key){
            case K_UP:
            std::cout << "up" << std::endl;
            break;
            
            case K_DOWN:
            std::cout << "down" << std::endl;
            break;
            
            case K_LEFT:
            std::cout << "left" << std::endl;
            break;
            
            case K_RIGHT:
            std::cout << "right" << std::endl;
            break;
        }
    }
}