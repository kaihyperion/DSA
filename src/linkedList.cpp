#include "my_algorithms.h"
#include <iostream>

// LinkedList implementation
LinkedList::Node* LinkedList::createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    deleteList();
}

void LinkedList::insertAtEnd(int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::deleteNode(int val) {
    if (head == nullptr) return;
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* curr = head;
    Node* prev = nullptr;
    while (curr != nullptr && curr->data != val) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr) return;
    prev->next = curr->next;
    delete curr;
}

void LinkedList::printList() const {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

void LinkedList::deleteList() {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

bool LinkedList::contains(int val) const {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == val) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Algorithm implementations
int findMax(const std::vector<int>& nums) {
    if (nums.empty()) return INT_MIN;
    int maxVal = nums[0];
    for (int num : nums) {
        if (num > maxVal) {
            maxVal = num;
        }
    }
    return maxVal;
}

bool isPalindrome(const std::string& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}