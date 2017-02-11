#include "simple.hpp"

#include <stack>

node::node(int value, node* left, node* right)
: value(value), left(left), right(right)
{ }

node::~node()
{
    delete left;
    delete right;
}

void node::traverse_preorder(std::function<void (int)> visit)
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

void node::traverse_inorder(std::function<void (int)> visit)
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