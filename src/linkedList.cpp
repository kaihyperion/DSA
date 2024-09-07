#include "my_algorithms.h"
#include <iostream>
#include <unordered_set>

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

int LinkedList::countElement(int val) const {
    Node* curr = head;
    int count = 0;
    while (curr != nullptr){
        if (curr -> data == val) count++;
        curr = curr->next;
    }
    return count;
}

// Chapter 2.1 Remove Dups: Write  code to remove duplicates from an unsorted linked list
void LinkedList::removeDups() {
    if (head == nullptr) return;

    std::unordered_set<int> seen;
    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr){
        if (seen.contains(curr->data)){
            prev->next = curr->next;
            delete curr;
        } else {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}

// Chapter 2 - 2.2 Return Kth to Last
// Implement an algorithm to find the kth to last element of a singly linked list.
int LinkedList::printKthToLast(int k) const {
    // idea: move the fast pointer kth step forward. then slow and fast point move together until end
    // Best plausible time complexity O(N) we have to know the end so we must traverse
    if (head == nullptr) return -1;

    Node* fast = head;
    Node* slow = head;

    while (fast->next != nullptr && k > 0){
        fast = fast->next;
        k--;
    }
    // if k is greater than length of singly linked list
    if (fast->next == nullptr && k>0){
        return -1;
    }
    if (fast -> next == nullptr && k == 0){
        return slow->data;
    }

    while (fast->next != nullptr){
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;

}

// 2.5 sum lists. 2 numbers represented in linked list. each node contains a single digit. digits are stored in reverse order, such that the1's digit is at the head of hte list. write afunction that adds the two nubmerw and retuns the sum as linked list'
LinkedList LinkedList::addLists(const LinkedList& list1, const LinkedList& list2) {
    Node* l1 = list1.getHead();
    Node* l2 = list2.getHead();
    LinkedList result;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2){
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        result.insertAtEnd(sum%10);
    }
    return result;
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



