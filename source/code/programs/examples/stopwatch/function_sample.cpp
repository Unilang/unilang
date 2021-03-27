#include "include/stopwatch.h"
#include <deque>
#include <iostream>
#include <vector>

int main() {
  const auto deque_samples = stopwatch::sample<100>([] {
    std::deque<int> deque;
    for (std::size_t i = 0; i < 10000; ++i) {
      deque.insert(deque.begin(), i);
    }
  });

  const auto vector_samples = stopwatch::sample<100>([] {
    std::vector<int> vector;
    for (std::size_t i = 0; i < 10000; ++i) {
      vector.insert(vector.begin(), i);
    }
  });

  std::cout << "median for deque: " << deque_samples[49].count() << std::endl;
  std::cout << "median for vector: " << vector_samples[49].count() << std::endl;
}