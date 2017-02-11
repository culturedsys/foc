#include "queue.hpp"
#include "../errors.hpp"

void queue::enqueue(int value)
{
    node* new_node = allocator.get_node();
    new_node->value = value;
    new_node->next = nullptr;

    if (front == nullptr) 
    {
        front = new_node;
    } else 
    {
        rear->next = new_node;
    }

    rear = new_node;
}

int queue::unqueue()
{
    if (front == nullptr)
    {
        throw UNDERFLOW;
    }

    node* removed = front;
    front = front->next;

    int result = removed->value;
    allocator.release(removed);

    return result;
}