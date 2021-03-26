#include <boost/asio/thread_pool.hpp>
#include <boost/asio/post.hpp>
#include <thread>
#include <iostream>

int main(){
    
    int threadNumbers = std::thread::hardware_concurrency();
    boost::asio::thread_pool pool(threadNumbers);

    for (size_t i = 0; i < 50; ++i){
        boost::asio::post(pool, [=]() {
          std::cout << i << std::endl;
        });
    }
    pool.join();
}