// This file defines the implementation for tree operations
#include "my_algorithms.h"
#include <iostream>

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