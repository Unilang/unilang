#include "code/utilities/types/tree/bst/tree_traversal.hpp"
#include "code/utilities/data_structures/tree/bst/binary_node.hpp"
#include "code/utilities/types/tree/bst/annotated_bst_fix.hpp"
#include "code/utilities/types/tree/bst/annotated_bst_state.hpp"
#include "code/utilities/data_structures/tree/bst/binary_nodes.hpp"
#include "code/utilities/types/tree/bst/prebuilt_bst_trees.hpp"
#include "code/programs/puzzles/hackerrank/bst_swap_solution_geeks_five_ptrs.hpp"
#include "gtest/gtest.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>

TEST(bst_inorder_throw_discrepancy, NonAdjacent_1) {
    
    //setup state
    // Annotated_Bst_State state;
    // state.a = &root;
    // state.b = nullptr;
    // state.root = &root;
    // state.current_photo = 0;
    // state.all_nodes = Tree_Traversal::inorder_traversal_as_node_list(state.root);
    // state.val_heights = Tree_Traversal::get_binary_node_levels(&root);
    // state.original_connections = Tree_Traversal::get_all_directed_relationships(&root);
    
    auto x = Prebuilt_Bst_Trees::TwoNodesSwapped_NonAdjecent_Example13();
    //auto x = Prebuilt_Bst_Trees::TwoNodesSwapped_Adjecent_Example1();
    
    
    //setup state
    auto real_root = *x.nodes[0];
    Annotated_Bst_State state;
    state.a = &real_root;
    state.b = nullptr;
    state.root = &real_root;
    state.draw_photo = true;
    state.current_photo = 0;
    state.all_nodes = Tree_Traversal::inorder_traversal_as_node_list(state.root);
    state.val_heights = Tree_Traversal::get_binary_node_levels(state.root);
    state.original_connections = Tree_Traversal::get_all_directed_relationships(state.root);
    state.swapped_vals = Bst_Swap_Solution_Geeks_Five_Ptrs::vals_to_swap(state.root);
    
    Annotated_Bst_Fix::fix(state);
    
    //Tree_Traversal::morris_traversal(&real_root,[&](BinaryNode<int>* c){
    //    
    //});
}





