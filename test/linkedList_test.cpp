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

void testRemoveDups() {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(3);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    std::cout << "Linked list before Duplication removal: ";
    list.printList();

    list.removeDups();
    std::cout << "Linked list after Duplication removal: ";
    list.printList();


    assert(list.contains(3) == true);
    assert(list.countElement(3) == 1);
}

void testKthToLast() {
    LinkedList list;
    std::array <int, 6> ls {1,2,3,4,5,6};
    for (int i : ls){
        list.insertAtEnd(i);
    }
    assert(list.printKthToLast(3) == 3);
    assert(list.printKthToLast(1) == 5);
    assert(list.printKthToLast(10) == -1);

}

void testSumLists() {
    LinkedList list1;
    LinkedList list2;
    std::array <int, 3> ls1 {7,1,6};
    for (int i : ls1){
        list1.insertAtEnd(i);
    }
    std::array <int, 3> ls2 {5,9,2};
    for (int i : ls2){
        list2.insertAtEnd(i);
    }
    LinkedList result = LinkedList::addLists(list1, list2);
    std::cout << "Result: ";
    result.printList();

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
    testRemoveDups();
    testKthToLast();
    testSumLists();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}