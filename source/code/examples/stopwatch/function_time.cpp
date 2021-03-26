#include "include/stopwatch.h"
#include <iostream>

int main() {
  const auto cycles = stopwatch::time([] {
    for (std::size_t i = 0; i < 10; ++i) {
      std::cout << i << std::endl;
    }
  });

  std::cout << "To print out 10 numbers, it took " << cycles.count()
            << " cycles." << std::endl;
}