#include "my_algorithms.h"
#include <iostream>

int main() {
    Tree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    std::cout << "Tree structure:" << std::endl;
    tree.showTree();

    std::cout << "Search for 3: " << (tree.search(3) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 8: " << (tree.search(8) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 10: " << (tree.search(10) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 7: " << (tree.search(7) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 1: " << (tree.search(1) ? "Found" : "Not Found") << std::endl;

    std::cout << "In-order Traversal" << std::endl;
    tree.inOrderTraversal();
    std::cout << "done" << std::endl;
    std::cout << "Pre-order Traversal" << std::endl;
    tree.preOrderTraversal();
    std::cout << "done" << std::endl;
    std::cout << "Post-order Traversal" << std::endl;
    tree.postOrderTraversal();
    std::cout << "done" << std::endl;
    tree.clear();
    return 0;
}