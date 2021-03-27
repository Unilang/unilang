#include "include/stopwatch.h"
#include <chrono>
#include <iostream>
#include <thread>

int main() {
  const auto timer = stopwatch::make_timer(std::chrono::seconds(10));
  while (!timer.done()) {
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(
                     timer.remaining())
                     .count()
              << " seconds remain." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  std::cout << "10 seconds have elapsed" << std::endl;
}