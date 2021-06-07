#pragma once

template <typename T>
struct BinaryNode {
    
    BinaryNode(T val):
    val(val) {}
    
    BinaryNode()
    {}
        
    T val;
    struct BinaryNode *left = nullptr;
    struct BinaryNode *right = nullptr;
};
