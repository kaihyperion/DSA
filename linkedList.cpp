#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <sstream>


class LinkedList {

private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

    Node* createNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        return newNode;
    }


public:
/* Creating a Node structure and basic Linked List structure*/
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        deleteList();
    }



    // Function to insert a node at the end of the list
    void insertAtEnd(int data) {
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

    // Function to delete a node with a given value
    void deleteNode(int val) {
        if (head == nullptr) return; // If the list is empty, nothing to delete

        // If the head node itself holds the value to be deleted
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;

        // Search for the node to be deleted, keep track of the previous node
        while (curr != nullptr && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }

        // If the value was not found in the list
        if (curr == nullptr) return;

        // Unlink the node from the linked list
        prev->next = curr->next;
        delete curr; // Free the memory of the deleted node
    }


    // Function to print the linked list
    void printList() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Function to delete the entire linked list
    void deleteList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class Solution {
public:
    void linkedlist_basic_test() {
        LinkedList linkedlist;
        linkedlist.insertAtEnd(1);
        linkedlist.insertAtEnd(2);
        linkedlist.insertAtEnd(3);
        linkedlist.insertAtEnd(4);

        std::cout << "Linked list before deletion: ";
        linkedlist.printList();

        linkedlist.deleteNode(3);

        std::cout << "Linked list after deletion: ";
        linkedlist.printList();
    }   

};




int main() {
    Solution solution;

    // Test case 1 (node is good creeated)
    solution.linkedlist_basic_test();
    return 0;
}

