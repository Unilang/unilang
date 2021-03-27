#include "code/utilities/output/printers/lib.hpp"
#include "code/utilities/time/sleeping/lib.hpp"

int main(){
    
    int i = 101;
    while(true){
        std::cout << i << std::endl;
        --i;
        std::cout.flush();
        Sleep_For_N_Seconds(1);
        Move_Cursor_Up();
        Clear_Terminal3();
    }
    
}
