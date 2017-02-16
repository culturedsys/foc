#include "unthreaded.hpp"

#include <stack>

unthreaded::node::node(int value, node* left, node* right)
: value(value), left(left), right(right)
{ }

unthreaded::node::~node()
{
    delete left;
    delete right;
}

void unthreaded::node::traverse_preorder(std::function<void (int)> visit)
{
    std::stack<node*> pending;
    node* current = this;

    while (true) 
    {
        if (current != nullptr)
        {
            visit(current->value);
            pending.push(current);
            current = current->left;
        } else {
            if (pending.empty()) 
            {
                break;
            }

            current = pending.top();
            pending.pop();      

            current = current->right;      
        }
    }
}

void unthreaded::node::traverse_inorder(std::function<void (int)> visit)
{
    std::stack<node*> pending;
    node* current = this;

    while (true) 
    {
        if (current != nullptr)
        {
            pending.push(current);
            current = current->left;
        } else {
            if (pending.empty()) 
            {
                break;
            }

            current = pending.top();            
            pending.pop();        
 
            visit(current->value);
 
            current = current->right;
        }
    }
}

void unthreaded::node::insert_left(node* n)
{
    n->left = this->left;
    n->right = nullptr;
    this->left = n; 
}

void unthreaded::node::insert_right(node* n)
{
    n->right = this->right;
    n->left = nullptr;
    this->right = n;
}