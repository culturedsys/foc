#include "bst.hpp"

using namespace bst;

bst::node::node(int value, node* left, node* right)
: value(value), left(left), right(right)
{ }

bst::node::~node()
{
    delete left;
    delete right;
}

// Insert the given value into the BST rooted at this node.
void bst::node::insert(int newValue)
{
    // This is a right-biased subtree (i.e., equal values go on the right).
    if (newValue < value)
    {
        if (left == nullptr)
            left = new node(newValue, nullptr, nullptr);
        else
            left->insert(newValue);
    }
    else 
    {
        if (right == nullptr)
            right = new node(newValue, nullptr, nullptr);
        else
            right->insert(newValue);
    }
} 


// Return the first node in the tree with the given value, or nullptr if there
// is none.
node* bst::node::find(int searchValue)
{
    if (searchValue < value)
        if (left == nullptr)
            return nullptr;
        else
            return left->find(searchValue);
    else if (searchValue > value)
        if (right == nullptr)
            return nullptr;
        else
            return right->find(searchValue);
    else
        return this;
}

// Remove the first node containing the given value from the tree, if one
// exists. Return the root of the resulting tree.
node* bst::node::remove(int value)
{    
    node* target = this;
    node* parent = nullptr;
    
    while (target != nullptr && target->value != value)
    {
        parent = target;
        if (value < target->value)
            target = target->left;
        else
            target = target->right;
    }

    if (target == nullptr)
        return this;

    node* child;

    if (target->left == nullptr)
    {
        child = target->right;
    }
    else if (target->right == nullptr)
    {
        child = target->left;
    }
    else
    {
        // Child should be target's inorder successer, i.e., the left-most
        // child of target's right child. 
        child = target->right;
        if (child->left != nullptr)
        {
            node* old_parent;
            do
            {
                old_parent = child;
                child = child->left;
            } while (child->left != nullptr);

            // Replace child with it's right subtree as left child of
            // old_parent. This preserves the binary search tree property, and
            // free's child's right subtree to hold the target's right
            // subtree.
            old_parent->left = child->right;            
        }

        child->right = target->right;

        // Child is the inorder successor of target, so by definition has no
        // left subtree.
        child->left = target->left;
    }


    node* result = this;
    if (target == this)
        result = child;
    else if (parent->left == target)
        parent->left = child;
    else
        parent->right = child;

    target->left = nullptr;
    target->right = nullptr;
    delete target;

    return result;
}