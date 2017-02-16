/**
 * A simple, i.e. non-threaded implementation of a binary tree.
 */

#ifndef BINARYTREE_SIMPLE_HPP
#define BINARYTREE_SIMPLE_HPP

#include <functional>

namespace unthreaded {

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

    void insert_left(node* n);
    void insert_right(node* n);
};

}
#endif
