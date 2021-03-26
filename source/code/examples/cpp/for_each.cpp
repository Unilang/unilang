#include <execution>
#include <algorithm>

int main(){

    int x = 0;
    std::mutex m;
    int a[] = {1,2};
    std::for_each(std::execution::par, std::begin(a), std::end(a), [&](int) {
      std::lock_guard<std::mutex> guard(m);
      ++x; // correct
    });

}