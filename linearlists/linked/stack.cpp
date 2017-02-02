#include "stack.hpp"
#include "../errors.hpp"

using namespace linked;

stack::stack(int capacity)
    : allocator(capacity),
      top(nullptr)
{ }

void stack::push(int value)
{
    node* new_node = allocator.get_node();
    new_node->value = value;
    new_node->next = top;
    top = new_node;
}

int stack::pop()
{
    if (top == nullptr)
    {
        throw UNDERFLOW;
    }

    node*  result_node = top;
    top = top->next;

    int result = result_node->value;
    allocator.release(result_node);

    return result;
}