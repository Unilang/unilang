#pragma once
#include <vector>
#include <memory>
#include "code/utilities/data_structures/tree/bst/binary_nodes.hpp"


//a bst tree example for a common programming problem where two nodes are swapped and they need to be fixed
struct Bst_Tree_Example {
    BinaryNodes<int> tree;
    
    //if empty than the tree is already correct
    std::vector<std::pair<BinaryNode<int>*,BinaryNode<int>*>> swapped_nodes;
};
