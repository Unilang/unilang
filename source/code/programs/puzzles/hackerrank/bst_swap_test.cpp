#include "code/utilities/types/tree/bst/tree_traversal.hpp"
#include "code/programs/puzzles/hackerrank/bst_swap_solution_sliding_window_two_ptrs.hpp"
#include "code/programs/puzzles/hackerrank/bst_swap_solution_in_out.hpp"
#include "code/programs/puzzles/hackerrank/bst_swap_solution_geeks_five_ptrs.hpp"
#include "code/programs/puzzles/hackerrank/bst_swap_solution_geeks_four_ptrs.hpp"
#include "code/programs/puzzles/hackerrank/bst_swap_solution_geeks_three_ptrs.hpp"
#include "code/programs/puzzles/hackerrank/bst_swap_algorithm.hpp"
#include "code/programs/puzzles/hackerrank/bst_swap_solution.hpp"
#include "code/utilities/data_structures/tree/bst/binary_nodes.hpp"
#include "code/utilities/types/tree/bst/prebuilt_bst_trees.hpp"
#include "gtest/gtest.h"
#include <algorithm>
#include <vector>
#include <utility>


std::string show_discrepencies(std::vector<std::pair<int,int>> const& discrepencies){
  std::string str;
  str += "Those discrepancies are:";
  str += "\n";
  for (auto const& x: discrepencies){
    str += std::to_string(x.first) + " " + std::to_string(x.second) + "\n";
  }
  return str;
}

void wrong_by_only_two_nodes(std::vector<int> nodes){
  auto sorted = nodes;
  std::sort(sorted.begin(),sorted.end());
  
  std::vector<std::pair<int,int>> discrepencies;
  for (size_t i = 0; i < sorted.size(); ++i){
    if (nodes[i] != sorted[i]){
      discrepencies.emplace_back(std::make_pair(nodes[i],sorted[i]));
    }
  }
  EXPECT_EQ(discrepencies.size(),2) << show_discrepencies(discrepencies);
}

void check_algorithm_fixes_tree(BinaryNode<int> & root, Bst_Swap_Algorithm const& algo){
  
  //the tree SHOULD NOT be sorted before we start
  auto before = Tree_Traversal::inorder_traversal_as_list(&root);
  EXPECT_FALSE(std::is_sorted(before.begin(),before.end()));
  
  //in fact, it should only be wrong by two nodes
  //we don't accept trees that are already fixed or broken beyond two nodes out of place
  wrong_by_only_two_nodes(before);
  
  //Time to fix the tree, and confirm that we actually fixed it.
  Bst_Swap_Solution::fix_bst(&root,algo);
  auto after = Tree_Traversal::inorder_traversal_as_list(&root);
  EXPECT_TRUE(std::is_sorted(after.begin(),after.end()));
}

void check_every_swap_combination(BinaryNode<int> & root, Bst_Swap_Algorithm const& algo){
    auto ordered = Tree_Traversal::inorder_traversal_as_node_list(&root);
    for (size_t i = 0; i < ordered.size(); ++i){
      for (size_t j = 0; j < ordered.size(); ++j){
        if (ordered[i]->val != ordered[j]->val){
          std::swap(ordered[i]->val,ordered[j]->val);
          //std::cout << "swapped " << ordered[i]->val << " " << ordered[j]->val << std::endl;
          check_algorithm_fixes_tree(root,algo);
        }
      }
    }
}



// a linked list is a special kind of tree in which there exists only 1 childless node.
// all other trees have 2 or more childless nodes.
// the hickey hijack requires that 1 pointer capture a childless node, in which the available child storage can be used to connect back to the root,
// then using the final child storage, connect to another childless node in order to gain two pointers of additional storage during later traversal.
// this transformation renders the original pointer the ability of two pointers indirectly, tags both of the childless nodes involved, and ensures
// the original pointer can get back to the root.  From this point, we perform a modified morris traversal in which we capture the first discrepancy,
// in the first pointers indirected storage.  Using the first pointer's indirected storage, the morris traversal is able to complete, with knowledge of the
// first node that needs swapped, and knowledge of how to return to the root.  At this point, we perform a modified reverse morris traversal choosing to forget
// how the first pointer could return to the root,  The second traversal will identify the second node, swap the values, and complete with lost knowledge of the root.
// as the tree is fixed, deriving the root can be performed by the first pointer.  Pointer A and B work together to repair the tree.


std::vector<Bst_Swap_Algorithm> algorithms_to_test(){
  std::vector<Bst_Swap_Algorithm> x;
  x.emplace_back(Bst_Swap_Algorithm::MORRIS_HICKEY_TWO);
  x.emplace_back(Bst_Swap_Algorithm::HACKERRANK_RECURSIVE_FIVE);
  x.emplace_back(Bst_Swap_Algorithm::HACKERRANK_RECURSIVE_FOUR);
  x.emplace_back(Bst_Swap_Algorithm::HACKERRANK_RECURSIVE_THREE);
  x.emplace_back(Bst_Swap_Algorithm::SLIDING_WINDOW_AND_PAIR);
  x.emplace_back(Bst_Swap_Algorithm::INORDER_OUTORDER_THREE);
  return x;
}



TEST(BST_Fix, NonAdjacent_1) {
    for (auto algo: algorithms_to_test()){
      auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_NonAdjecent_Example1();
      check_algorithm_fixes_tree(*tree.nodes[0],algo);
    }
}
TEST(BST_Fix, NonAdjacent_2) {
    for (auto algo: algorithms_to_test()){
      auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_NonAdjecent_Example2();
      check_algorithm_fixes_tree(*tree.nodes[0],algo);
    }
}
TEST(BST_Fix, NonAdjacent_3) {
    for (auto algo: algorithms_to_test()){
      auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_NonAdjecent_Example3();
      check_algorithm_fixes_tree(*tree.nodes[0],algo);
    }
}
TEST(BST_Fix, NonAdjacent_4) {
    for (auto algo: algorithms_to_test()){
      auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_NonAdjecent_Example4();
      check_algorithm_fixes_tree(*tree.nodes[0],algo);
    }
}
TEST(BST_Fix, NonAdjacent_5) {
    for (auto algo: algorithms_to_test()){
      auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_NonAdjecent_Example5();
      check_algorithm_fixes_tree(*tree.nodes[0],algo);
    }
}
TEST(BST_Fix, NonAdjacent_6) {
    for (auto algo: algorithms_to_test()){
      auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_NonAdjecent_Example6();
      check_algorithm_fixes_tree(*tree.nodes[0],algo);
    }
}
TEST(BST_Fix, NonAdjacent_7) {
    for (auto algo: algorithms_to_test()){
      auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_NonAdjecent_Example7();
      check_algorithm_fixes_tree(*tree.nodes[0],algo);
    }
}
TEST(BST_Fix, NonAdjacent_8) {
    for (auto algo: algorithms_to_test()){
      auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_NonAdjecent_Example8();
      check_algorithm_fixes_tree(*tree.nodes[0],algo);
    }
}
TEST(BST_Fix, NonAdjacent_9) {
    for (auto algo: algorithms_to_test()){
      auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_NonAdjecent_Example9();
      check_algorithm_fixes_tree(*tree.nodes[0],algo);
    }
}
TEST(BST_Fix, NonAdjacent_10) {
    for (auto algo: algorithms_to_test()){
      auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_NonAdjecent_Example10();
      check_algorithm_fixes_tree(*tree.nodes[0],algo);
    }
}
TEST(BST_Fix, NonAdjacent_11) {
    for (auto algo: algorithms_to_test()){
      auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_NonAdjecent_Example11();
      check_algorithm_fixes_tree(*tree.nodes[0],algo);
    }
}
TEST(BST_Fix, NonAdjacent_12) {
    for (auto algo: algorithms_to_test()){
      auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_NonAdjecent_Example12();
      check_algorithm_fixes_tree(*tree.nodes[0],algo);
    }
}
// TEST(BST_Fix, NonAdjacent_13) {
//     for (auto algo: algorithms_to_test()){
//       auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_NonAdjecent_Example13();
//       check_algorithm_fixes_tree(*tree.nodes[0],algo);
//     }
// }


// TEST(BST_Fix, Adjacent_1) {
    
//     for (auto algo: algorithms_to_test()){
//       auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_Adjecent_Example1();
//       check_algorithm_fixes_tree(*tree.nodes[0],algo);
//     }
// }
// TEST(BST_Fix, Adjacent_2) {
    
//     for (auto algo: algorithms_to_test()){
//       auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_Adjecent_Example2();
//       check_algorithm_fixes_tree(*tree.nodes[0],algo);
//     }
// }
// TEST(BST_Fix, Adjacent_3) {
    
//     for (auto algo: algorithms_to_test()){
//       auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_Adjecent_Example3();
//       check_algorithm_fixes_tree(*tree.nodes[0],algo);
//     }
// }
// TEST(BST_Fix, Adjacent_4) {
//     for (auto algo: algorithms_to_test()){
//       auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_Adjecent_Example4();
//       check_algorithm_fixes_tree(*tree.nodes[0],algo);
//     }
// }
// TEST(BST_Fix, Adjacent_5) {
//     for (auto algo: algorithms_to_test()){
//       auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_Adjecent_Example5();
//       check_algorithm_fixes_tree(*tree.nodes[0],algo);
//     }
// }
// TEST(BST_Fix, Adjacent_6) {
//     for (auto algo: algorithms_to_test()){
//       auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_Adjecent_Example6();
//       check_algorithm_fixes_tree(*tree.nodes[0],algo);
//     }
// }
// TEST(BST_Fix, Adjacent_7) {
//     for (auto algo: algorithms_to_test()){
//       auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_Adjecent_Example7();
//       check_algorithm_fixes_tree(*tree.nodes[0],algo);
//     }
// }
// TEST(BST_Fix, Adjacent_8) {
//     for (auto algo: algorithms_to_test()){
//       auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_Adjecent_Example8();
//       check_algorithm_fixes_tree(*tree.nodes[0],algo);
//     }
// }
// TEST(BST_Fix, Adjacent_9) {
//     for (auto algo: algorithms_to_test()){
//       auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_Adjecent_Example9();
//       check_algorithm_fixes_tree(*tree.nodes[0],algo);
//     }
// }
// TEST(BST_Fix, Adjacent_10) {
//     for (auto algo: algorithms_to_test()){
//       auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_Adjecent_Example10();
//       check_algorithm_fixes_tree(*tree.nodes[0],algo);
//     }
// }
// TEST(BST_Fix, Adjacent_11) {
//     for (auto algo: algorithms_to_test()){
//       auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_Adjecent_Example11();
//       check_algorithm_fixes_tree(*tree.nodes[0],algo);
//     }
// }
// TEST(BST_Fix, Adjacent_12) {
//     for (auto algo: algorithms_to_test()){
//       auto tree = Prebuilt_Bst_Trees::TwoNodesSwapped_Adjecent_Example12();
//       check_algorithm_fixes_tree(*tree.nodes[0],algo);
//     }
// }
// TEST(BST_Fix, Every_Swap_1) {
//   for (auto algo: algorithms_to_test()){
//     auto tree = Prebuilt_Bst_Trees::Correct_Tree_Example1();
//     check_every_swap_combination(*tree.nodes[0],algo);
//   }
// }
// TEST(BST_Fix, Every_Swap_2) {
//   for (auto algo: algorithms_to_test()){
//     auto tree = Prebuilt_Bst_Trees::Correct_Tree_Example2();
//     check_every_swap_combination(*tree.nodes[0],algo);
//   }
// }
// TEST(BST_Fix, Every_Swap_3) {
//   for (auto algo: algorithms_to_test()){
//     auto tree = Prebuilt_Bst_Trees::Correct_Tree_Example3();
//     check_every_swap_combination(*tree.nodes[0],algo);
//   }
// }
// TEST(BST_Fix, Every_Swap_4) {
//   for (auto algo: algorithms_to_test()){
//     auto tree = Prebuilt_Bst_Trees::Correct_Tree_Example4();
//     check_every_swap_combination(*tree.nodes[0],algo);
//   }
// }
// TEST(BST_Fix, Every_Swap_5) {
//   for (auto algo: algorithms_to_test()){
//     auto tree = Prebuilt_Bst_Trees::Correct_Tree_Example5();
//     check_every_swap_combination(*tree.nodes[0],algo);
//   }
// }
// TEST(BST_Fix, Every_Swap_6) {
//   for (auto algo: algorithms_to_test()){
//     auto tree = Prebuilt_Bst_Trees::Correct_Tree_Example6();
//     check_every_swap_combination(*tree.nodes[0],algo);
//   }
// }
// TEST(BST_Fix, Every_Swap_7) {
//   for (auto algo: algorithms_to_test()){
//     auto tree = Prebuilt_Bst_Trees::Correct_Tree_Example7();
//     check_every_swap_combination(*tree.nodes[0],algo);
//   }
// }
// TEST(BST_Fix, Every_Swap_8) {
//   for (auto algo: algorithms_to_test()){
//     auto tree = Prebuilt_Bst_Trees::Correct_Tree_Example8();
//     check_every_swap_combination(*tree.nodes[0],algo);
//   }
// }
// TEST(BST_Fix, Every_Swap_9) {
//   for (auto algo: algorithms_to_test()){
//     auto tree = Prebuilt_Bst_Trees::Correct_Tree_Example9();
//     check_every_swap_combination(*tree.nodes[0],algo);
//   }
// }

// TEST(BST_Fix, Every_Swap_10) {
//   for (auto algo: algorithms_to_test()){
//     auto tree = Prebuilt_Bst_Trees::Correct_Tree_Example10();
//     check_every_swap_combination(*tree.nodes[0],algo);
//   }
// }

// TEST(BST_Fix, Every_Swap_11) {
//   for (auto algo: algorithms_to_test()){
//     auto tree = Prebuilt_Bst_Trees::Correct_Tree_Example11();
//     check_every_swap_combination(*tree.nodes[0],algo);
//   }
// }
// TEST(BST_Fix, Every_Swap_12) {
//   for (auto algo: algorithms_to_test()){
//     auto tree = Prebuilt_Bst_Trees::Correct_Tree_Example12();
//     check_every_swap_combination(*tree.nodes[0],algo);
//   }
// }
// TEST(BST_Fix, Every_Swap_13) {
//   for (auto algo: algorithms_to_test()){
//     auto tree = Prebuilt_Bst_Trees::Correct_Tree_Example13();
//     check_every_swap_combination(*tree.nodes[0],algo);
//   }
// }

// TEST(BST_Fix, Every_Swap_14) {
//   for (auto algo: algorithms_to_test()){
//     auto tree = Prebuilt_Bst_Trees::Correct_Tree_Example14();
//     check_every_swap_combination(*tree.nodes[0],algo);
//   }
// }

// TEST(BST_Fix, Every_Swap_15) {
//   for (auto algo: algorithms_to_test()){
//     auto tree = Prebuilt_Bst_Trees::Correct_Tree_Example15();
//     check_every_swap_combination(*tree.nodes[0],algo);
//   }
// }

// TEST(BST_Fix, Every_Swap_16) {
//   for (auto algo: algorithms_to_test()){
//     auto tree = Prebuilt_Bst_Trees::Correct_Tree_Example16();
//     check_every_swap_combination(*tree.nodes[0],algo);
//   }
// }

// TEST(BST_Fix, Example_Hickey_Hijack_Easy) {
//   for (auto algo: algorithms_to_test()){
//     auto tree = Prebuilt_Bst_Trees::Example_Hickey_Hijack_Easy();
//     check_every_swap_combination(*tree.nodes[0],algo);
//   }
// }

// TEST(BST_Fix, Example_Hickey_Hijack_Hard) {
//   for (auto algo: algorithms_to_test()){
//     auto tree = Prebuilt_Bst_Trees::Example_Hickey_Hijack_Hard();
//     check_every_swap_combination(*tree.nodes[0],algo);
//   }
// }







