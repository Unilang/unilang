#include "forest/AVLTree.hpp"
// #include <forest/BinarySearchTree.hpp>
#include <iostream>
#include <string>

class Node {
public:
  Node() = default;
  Node(int key, const std::string &value) : mKey(key), mValue(value){};
  ~Node() = default;

public:
  bool operator<(const Node &other) const { return mKey < other.mKey; }
  friend bool operator<(const Node &, const int);
  friend bool operator<(const int, const Node &);
  friend std::ostream &operator<<(std::ostream &, const Node &);

public:
  void setKey(int key) { mKey = key; }
  void setValue(const std::string &value) { mValue = value; }

public:
  int getKey() { return mKey; }
  std::string getValue() { return mValue; }

private:
  int mKey = 0;
  std::string mValue;
};

bool operator<(const Node &lhs, const int rhs) { return lhs.mKey < rhs; }
bool operator<(const int lhs, const Node &rhs) { return lhs < rhs.mKey; }
std::ostream &operator<<(std::ostream &os, const Node &node) {
  os << "(" << node.mKey << ", " << node.mValue << ")" << std::endl;
  return os;
}

int main() {
  forest::AVLTree<Node> Tree;
  // forest::BinarySearchTree<Node> Tree;

  Tree.insert(Node(2 , "Thor"));
  Tree.insert(Node(4 , "Odin"));
  Tree.insert(Node(90, "Loki"));
  Tree.insert(Node(3 , "Baldr"));
  Tree.insert(Node(0 , "Frigg"));
  Tree.insert(Node(14, "Eir"));
  Tree.insert(Node(45, "Heimdall"));

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