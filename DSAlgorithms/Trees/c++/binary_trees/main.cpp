#include <iostream>
#include "binary_search_tree.h"

int main(int argc, const char** argv) {
    binary_search_tree<int> *tree = new binary_search_tree<int>;
    tree->insert(3);
    tree->insert(5);
    tree->insert(1);
    //tree->inorder_traversal();
    //tree->depth_first_traversal_iterative();
    //tree->depth_first_traversal_recursive();
    //tree->breadth_first_search_iterative();
    //std::cout<<tree->breadth_first_search_item_search(5)<<'\n';
    //std::cout<<tree->depth_first_search_sum_of_nodes()<<'\n';
    //std::cout<<tree->breath_first_search_sum_of_nodes()<<'\n';
    //std::cout<<tree->breath_first_search_min_node()<<'\n';
    std::cout<<tree->depth_first_search_min_node()<<'\n';
    return 0;
}