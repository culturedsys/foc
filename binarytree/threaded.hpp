/**
 * An implementation of a threaded binary tree.
 */

#ifndef BINARYTREE_THREADED_HPP
#define BINARY_TREE_THREADED_HPP

#include <functional>

namespace threaded
{

class node
{
    int value;

    bool left_tag;
    node* left;
    
    bool right_tag;
    node* right;

    node(int, bool, node*, bool, node*);
public:
    // Construct an empty tree
    node();

    ~node();

    // Add a node with the specified value as the left node of this node, and
    // return that node.
    node* insert_left(int value);

    // Add a node with the specified value as the right node of this node, and
    // return that node.
    node* insert_right(int value);

    node* inorder_successor();
    node* inorder_predecessor();

    node* preorder_successor();
    // Note that it's not straightforward to find the pre-order predecessor, 
    // as far as I can see.
    // node* preorder_predecessor();

    void traverse_preorder(std::function<void(int)>);
    void traverse_inorder(std::function<void(int)>);
};

}

#endif
