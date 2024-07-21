#ifndef MY_ALGORITHMS_H
#define MY_ALGORITHMS_H

#include <vector>
#include <string>

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

    Node* createNode(int data);

public:
    LinkedList();
    ~LinkedList();
    void insertAtEnd(int data);
    void deleteNode(int val);
    void printList() const;
    void deleteList();
    bool contains(int val) const;
};

// Add more algorithms and data structures as needed
int findMax(const std::vector<int>& nums);
bool isPalindrome(const std::string& s);

#endif // MY_ALGORITHMS_H