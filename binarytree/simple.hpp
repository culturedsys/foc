/**
 * A simple, i.e. non-threaded implementation of a binary tree.
 */

#ifndef BINARYTREE_SIMPLE_HPP
#define BINARYTREE_SIMPLE_HPP

#include <functional>

class node {
    int value;
    node* left;
    node* right;

public:
    node(int value, node* left, node* right);
    ~node();

    void traverse_preorder(std::function<void (int)>);
    void traverse_inorder(std::function<void (int)>);
    void traverse_postorder(std::function<void (int)>);
};
#endif