#include "deque.hpp"
#include "../errors.hpp"

deque::deque(int capacity)
    : allocator(capacity),
      ptr(nullptr)
{ }

void deque::insert_left(int value)
{
    node* new_node = allocator.get_node();
    new_node->value = value;
    
    if (ptr == nullptr) 
    {
        ptr = new_node;
        new_node->next = new_node;
    } else 
    {
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
}

void deque::insert_right(int value)
{
    insert_left(value);
    ptr = ptr->next;
}

int deque::remove_left()
{
    if (ptr == nullptr)
    {
        throw UNDERFLOW;
    }
    
    node* removed = ptr->next;
    
    if (removed == ptr)
    {
        ptr = nullptr;
    }
    else
    {
        ptr->next = removed->next;
    }   
    
    int result = removed->value;
    
    allocator.release(removed);
    return result;
}

int deque::remove_right()
{
    if (ptr == nullptr)
    {
        throw UNDERFLOW;
    }

    node* current = ptr->next;
    while (current->next != ptr)
    {
        current = current->next;
    }

    int result = ptr->value;
    current->next = ptr->next;
    allocator.release(ptr);
    ptr = current;

    return result;
}