#include "forest/AVLTree.hpp"
// #include <forest/BinarySearchTree.hpp>
#include <iostream>

int main() {
  forest::AVLTree<int> Tree;
  // forest::BinarySearchTree<int> Tree;

  Tree.insert(2);
  Tree.insert(4);
  Tree.insert(90);
  Tree.insert(3);
  Tree.insert(0);
  Tree.insert(14);
  Tree.insert(45);

  Tree.pre_order_traversal([](auto node) {
    std::cout << node << std::endl;
  });

  Tree.in_order_traversal([](auto node) {
    std::cout << node << std::endl;
  });

  Tree.post_order_traversal([](auto node) {
    std::cout << node << std::endl;
  });

  Tree.breadth_first_traversal([](auto node) {
    std::cout << node << std::endl;
  });

  if (auto min = Tree.minimum()) {
    std::cout << "min: " << min->get() << std::endl;
  }

  if (auto max = Tree.maximum()) {
    std::cout << "max: " << max->get() << std::endl;
  }

  Tree.remove(2);

  if (auto res = Tree.search(2)) {
    std::cout << "res: " << res->get() << std::endl;
  }

  Tree.clear();

  return 0;
}