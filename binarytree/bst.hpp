#ifndef BINARY_TREE_BST_HPP
#define BINARY_TREE_BST_HPP

#include "threaded.hpp"

namespace bst {
    class node 
    {
        int value;
        node* left;
        node* right;

    public:
        node(int value, node* left, node* right);
        node(int value) : node(value, nullptr, nullptr) { }

        ~node();

        void insert(int);
        node* find(int);
        node* remove(int);

        int getValue() { return value; }
    };
}

#endif