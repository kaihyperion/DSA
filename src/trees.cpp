// This file defines the implementation for tree operations
#include "my_algorithms.h"
#include <iostream>
#include <queue>
#include <stdexcept>

// Constrcutor: initializes the tree with an empty root
Tree::Tree() : root(nullptr){}

// Destructor: calls the clear function to delete all nodes
Tree::~Tree() {
    clear();
}

// Public insert function, calls the helper recursively
void Tree::insert(int value) {
    insertHelper(root, value);
}

// Private insert helper function for recursive insertion
void Tree::insertHelper(TreeNode*& node, int value) {
    if (!node) {
        node = new TreeNode(value);
    } else if (value < node->value) {
        insertHelper(node->left, value);
    } else {
        insertHelper(node->right, value);
    }
}

// Public search function, calls the helper recursively
bool Tree::search(int value) {
    return searchHelper(root, value);
}

// Private search helper function for recursive search
bool Tree::searchHelper(TreeNode* node, int value) {
    if (!node) {
        return false;
    } else if (value == node -> value) {
        return true;
    } else if (value < node->value) {
        return searchHelper(node->left, value);
    } else {
        return searchHelper(node->right, value);
    }
}

// Public clear function, calls the helper to delete all nodes
void Tree::clear() {
    clearHelper(root);
    root = nullptr;
}

// Private clear helper function to delete nodes recursively
void Tree::clearHelper(TreeNode* node) {
    if (node) {
        clearHelper(node->left);
        clearHelper(node->right);
        delete node;
    }
}

// Public showTree
void Tree::showTree() {
    showTreeHelper(root, "", true);
}

void Tree::showTreeHelper(TreeNode* node, std::string indent, bool isLeft){
    if (node){
        showTreeHelper(node->right, indent + (isLeft ? "        " : " |      "), false);

        // print current node
        std::cout << indent;
        if (isLeft) {
            std::cout << " \\--- ";
        } else {
            std::cout << " /--- ";
        }
        std::cout << node->value << std::endl;

        // print the left subtree
        showTreeHelper(node->left, indent + (isLeft ? "        " : " |      "), true);
    }
}

// Public inOrderTraversal
void Tree::inOrderTraversal() {
    inOrderTraversalHelper(root);
}

void Tree::inOrderTraversalHelper(TreeNode* node){
    if (node) {
        inOrderTraversalHelper(node->left);
        std::cout << node->value << " -> ";
        inOrderTraversalHelper(node->right);
    }
}

void Tree::preOrderTraversal() {
    preOrderTraversalHelper(root);
}

void Tree::preOrderTraversalHelper(TreeNode* node) {
    if (node) {
        std::cout << node->value << " -> ";
        preOrderTraversalHelper(node->left);
        preOrderTraversalHelper(node->right);
    }
}

void Tree::postOrderTraversal(){
    postOrderTraversalHelper(root);
}

void Tree::postOrderTraversalHelper(TreeNode* node){
    if (node) {
        postOrderTraversalHelper(node->left);
        postOrderTraversalHelper(node->right);
        std::cout << node->value << " -> ";
    }
}




// MIN_HEAP Tree

// first things first. constructor define
MinHeapTree::MinHeapTree() : root(nullptr), size(0) {}

// Insert operation
void MinHeapTree::insert(int value) {
    TreeNode* newNode = new TreeNode(value);

    if (root == nullptr) {
        root = newNode;     // if the heap is empty, set it as the root
    } else {
        // Find the correct position to insert (using BFS to keep completeness)
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (!curr->left) {
                // if left child doesn't exist, we insert in there. we are under assumption that it was already complete min heap tree. so if left is empty, that means it needs to be filled and nothing on right either.
                curr->left = newNode;
                newNode->parent = curr;
                break;
            } else {
                q.push(curr->left); // if left child does exist, we need to push into queue for next possible visit
            }

            if (!curr->right){
                curr->right = newNode;
                newNode->parent = curr;
                break;
            } else {
                q.push(curr->right);
            }
        }
    }

    size++;     // since we inserted one node, we gotta increase size of heap
    bubbleUp(newNode); // helper function call to restore heap property
}

// Bubble up helper function to maintain heap property  after insertion
void MinHeapTree::bubbleUp(TreeNode* node) {
    
}