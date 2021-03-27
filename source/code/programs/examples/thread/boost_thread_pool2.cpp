#include <boost/asio/thread_pool.hpp>
#include <boost/asio/post.hpp>
#include <thread>
#include <iostream>
#include "code/utilities/execution/thread_pool_getter.hpp"
#include "code/utilities/execution/thread_pool_loop.hpp"

int main(){
    
    //a thread pool
    auto pool = Thread_Pool_Getter::Get_Max();
    
    //a data structure
    std::vector<int> v {1,2,3,4,5,6,7,8,9,10};
    
    //an iteration with a lambda
    auto l = [](int i){ std::cout << i << std::endl; };
    Thread_Pool_Loop::Run(*pool,v,l);


}