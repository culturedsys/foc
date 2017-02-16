#include "threaded.hpp"

using namespace threaded;

threaded::node::node(int value, bool left_tag, node* left, 
                        bool right_tag, node* right)
    : value(value), left_tag(left_tag), left(left), 
        right_tag(right_tag), right(right)
{ }

threaded::node::node()
    : left_tag(true), left(this), right_tag(false), right(this)
{ }

threaded::node::~node()
{
    if (!left_tag)
    {
        delete left;
    }

    if (!right_tag)
    {
        delete right;
    }
}

node* threaded::node::insert_left(int value)
{
    node* new_node = new node(value, left_tag, left, true, this);
    left_tag = false;
    left = new_node;

    if (!new_node->left_tag)
    {
        node* pre = new_node->inorder_predecessor();
        pre->right = new_node;
    }

    return new_node;
}

node* threaded::node::insert_right(int value)
{
    node* new_node = new node(value, true, this, right_tag, right);
    right_tag = false;
    right = new_node;

    if (!new_node->right_tag)
    {
        node* succ = new_node->inorder_successor();
        succ->left = new_node;
    }

    return new_node;
}

node* threaded::node::inorder_predecessor()
{
    if (left_tag)
    {
        return left;
    }

    node* current = left;
    while (!current->right_tag)
    {
        current = current->right;
    }

    return current;
}

node* threaded::node::inorder_successor()
{
    if (right_tag)
    {
        return right;
    }

    node* current = right;
    while (!current->left_tag)
    {
        current = current->left;
    }

    return current;
}

node* threaded::node::preorder_successor()
{
    if (!left_tag)
    {
        return left;
    }

    node* current = this;

    while (current->right_tag)
    {
        current = current->right;
    }

    return current->right;
}

void threaded::node::traverse_inorder(std::function<void (int)> visit)
{
    node* current = inorder_successor();
    while (current != this)
    {
        visit(current->value);
        current = current->inorder_successor();
    }
}

void threaded::node::traverse_preorder(std::function<void (int)> visit)
{
    node* current = preorder_successor();
    while (current != this)
    {
        visit(current->value);
        current = current->preorder_successor();
    }
}