#ifndef LINKED_QUEUE_HPP
#define LINKED_QUEUE_HPP

#include "../allocator.hpp"
#include "node.hpp"

class queue
{
    node_allocator<node> allocator;
    node* front;
    node* rear;

public:
    queue(int capacity)
    : allocator(capacity), 
      front(nullptr),
      rear(nullptr)
    { }

    void enqueue(int value);

    int unqueue();
};

#endif
