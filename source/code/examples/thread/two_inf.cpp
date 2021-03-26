#include <thread>

int main(){
    
    //ya, ya, technically UB.  i dont care
    std::thread t1([&](){
        while (true){
        }
    });
    std::thread t2([&](){
        while(true){
        }
    });
    
    t1.join();
    t2.join();
}