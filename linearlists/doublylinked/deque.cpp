#include "deque.hpp"
#include <iostream>

deque::deque(int capacity)
  : allocator(capacity),
    left(nullptr),
    right(nullptr)
{ }

void deque::insert_left(int value)
{
    node* added = allocator.get_node();
    added->value = value;
    added->prev = nullptr;
    added->next = left;

    if (left == nullptr)
    {
        right = added;
    } else 
    {
        left->prev = added;
    }
    
    left = added;
}

void deque::insert_right(int value)
{
    node* added = allocator.get_node();
    added->value = value;
    added->next = nullptr;
    added->prev = right;

    if (left == nullptr)
    {
        left = added;
    }
    else
    {
        right->next = added;
    }

    right = added;
}

int deque::remove_left()
{
    if (left == nullptr)
    {
        throw UNDERFLOW;
    }

    node* removed = left;
    int result = removed->value;

    left = left->next;
    if (left != nullptr)
    {
        left->prev = nullptr;
    }

    allocator.release(removed);

    return result;
}

int deque::remove_right()
{
    if (left == nullptr)
    {
        throw UNDERFLOW;
    }

    node* removed = right;
    int result = removed->value;

    right = right->prev;
    if (right != nullptr)
    {
        right->next = nullptr;
    }
    allocator.release(removed);

    return result;
}