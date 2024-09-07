// This header file declares LinkedList class and Tree class and its helper function

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
    void removeDups();
    int countElement(int val) const;
    int printKthToLast(int k) const;

    Node* getHead() const {
        return head;
    }
    static LinkedList addLists(const LinkedList& list1, const LinkedList& list2);
};
// Add more algorithms and data structures as needed
int findMax(const std::vector<int>& nums);
bool isPalindrome(const std::string& s);



class Tree {
private:
    struct TreeNode {
        int value;
        TreeNode* left;
        TreeNode* right;

        // TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
        // above line is same as 
        TreeNode(int val) {
            value = val;
            left = nullptr;
            right = nullptr;
        }
    };

    TreeNode* root; // Pointer to the root node of the tree

public:
    // constructor and destructor
    Tree();
    ~Tree();
    // constructor and destructor values are in

    // Basic Operations 
    void insert(int value);
    bool search(int value);
    void clear();

    void showTree();
    
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();


private:
    // Helper functions
    void insertHelper(TreeNode*& node, int value);
    bool searchHelper(TreeNode* node, int value);
    void clearHelper(TreeNode* node);

    void showTreeHelper(TreeNode* node, std::string indent, bool isLeft);

    void inOrderTraversalHelper(TreeNode* node);

    void preOrderTraversalHelper(TreeNode* node);

    void postOrderTraversalHelper(TreeNode* node);
    
};

class MinHeapTree {
private:

    // Nested Private struct for TreeNode
    struct TreeNode {
        int value;
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;

        TreeNode(int val) : value(val), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    TreeNode* root; // pointer to the root node of the tree
    int size; // to keep track of # of nodes

    // helper function
    void bubbleUp(TreeNode* node);
    void bubbleDown(TreeNode* node);
    TreeNode* getLastNode();
    void removeLastNode(TreeNode* lastNode);


public:
    MinHeapTree();

    // min heap public operation
    void insert(int value);
    int extractMin();
    void showTree();

private:
    void showTreeHelper(TreeNode* node, std::string indent, bool isLeft);
};


#endif // MY_ALGORITHMS_H