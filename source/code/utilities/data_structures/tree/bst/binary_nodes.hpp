#pragma once
#include <vector>
#include <memory>
#include "code/utilities/data_structures/tree/bst/binary_node.hpp"

//kept alive on the heap
template <typename T>
struct BinaryNodes {
    std::vector<std::shared_ptr<BinaryNode<T>>> nodes;
};
