#include <iostream>
#include "code/utilities/games/patchwork/data/piece_getter.hpp"


int main(){
    
        auto all = Piece_Getter::Get();
        
        for (auto const& it: all){
            std::cout << it.shape;
            size_t count = std::count_if( it.shape.begin(), it.shape.end(), []( char c ){return c =='O';});
            
            for (size_t i = 0; i < 9; ++i){
                
                int total_score = 0;
                total_score += (it.buttons * (9-i));
                total_score += count;
                total_score -= it.time;
                total_score -= it.cost;
                
                std::cout << i+1 << ": " << total_score << std::endl;
            }
        }
}