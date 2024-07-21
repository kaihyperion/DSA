#include "../include/my_algorithms.h"
#include <iostream>
#include <cassert>

void testLinkedList() {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    std::cout << "Linked list before deletion: ";
    list.printList();

    list.deleteNode(3);
    std::cout << "Linked list after deletion: ";
    list.printList();

    assert(list.contains(2) == true);
    assert(list.contains(3) == false);
}

void testFindMax() {
    std::vector<int> nums = {1, 3, 5, 7, 9};
    assert(findMax(nums) == 9);

    nums = {-1, -3, -5, -7, -9};
    assert(findMax(nums) == -1);

    nums = {};
    assert(findMax(nums) == INT_MIN);
}

void testIsPalindrome() {
    assert(isPalindrome("racecar") == true);
    assert(isPalindrome("hello") == false);
    assert(isPalindrome("madam") == true);
}

int main() {
    testLinkedList();
    testFindMax();
    testIsPalindrome();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}