#include <iostream>
#include "binary_search_tree.h"

int main(int argc, const char** argv) {
    binary_search_tree<int> *tree = new binary_search_tree<int>;
    tree->insert(3);
    tree->insert(5);
    tree->insert(1);
    return 0;
}