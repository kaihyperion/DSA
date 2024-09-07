#include "my_algorithms.h"
#include <iostream>

int main() {
    MinHeapTree heap;

    heap.insert(10);
    heap.showTree();
    heap.insert(4);
    heap.showTree();
    heap.insert(9);
    heap.showTree();
    heap.insert(1);
    heap.showTree();

    heap.insert(7);
    heap.showTree();

    heap.insert(5);
    heap.showTree();


    std::cout << "Heap after insertions: " << std::endl;
    heap.showTree();

    std::cout << "Extracting minimum element: " << heap.extractMin() << std::endl;
    heap.showTree();
    std::cout << "Extracting minimum element: " << heap.extractMin() << std::endl;
    heap.showTree();

    return 0;
}