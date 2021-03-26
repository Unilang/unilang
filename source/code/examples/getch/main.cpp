#include <cstdio>
#include <iostream>

//not what i wanted
int main(){
    int k = 0;
    while (true){
        k = getchar();
        switch(k)
        {
                case 72: std::cout << "up" << std::endl;
                         std::cout.flush();
                         break;
                case 75: std::cout << "down" << std::endl;
                         std::cout.flush();
                         break;
                case 77: std::cout << "left" << std::endl;
                         std::cout.flush();
                         break;
                case 80: std::cout << "right" << std::endl;
                         std::cout.flush();
                         break; 
                default:
                    std::cout << k << std::endl;
        } 
    }
}