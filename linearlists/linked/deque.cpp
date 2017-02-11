/*
 * An implementation of the deque structure using a singly linked list.
 */

#include "deque.hpp"
#include "../errors.hpp"

void deque::insert_left(int value)
{
    node* new_node = allocator.get_node();

    new_node->value = value;
    new_node->next = left;

    if (left == nullptr)
    {
        right = new_node;
    }

    left = new_node;
}

void deque::insert_right(int value)
{
    node* new_node = allocator.get_node();

    new_node->value = value;
    new_node->next = nullptr;

    if (left == nullptr)
    {
        left = new_node;
    } 
    else
    {
        right->next = new_node;
    }

    right = new_node;
}

int deque::remove_left()
{
    if (left == nullptr)
    {
        throw UNDERFLOW;
    }

    node* remove = left;
    int result = remove->value;

    left = left->next;
    allocator.release(remove);

    return result;
}

int deque::remove_right()
{
    if (left == nullptr)
    {
        throw UNDERFLOW;
    }

    node* remove = right;
    int result = remove->value;

    if (left == right)
    {
        left = nullptr;
    }
    else
    {
        // As this is a singly-linked list, a full scan is the only way to
        // remove the last element.
        node* current = left;
        while (current->next != right)
        {
            current = current->next;
        }
        current->next = nullptr;
        right = current;
    }

    allocator.release(remove);

    return result;
}