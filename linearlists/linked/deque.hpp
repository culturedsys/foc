#ifndef LINKED_DEQUE_HPP
#define LINKED_DEQUE_HPP

#include "../allocator.hpp"
#include "node.hpp"

class deque
{
    node_allocator<node> allocator;
    node* left;
    node* right;
public:

    deque(int capacity)
        : allocator(capacity),
          left(nullptr),
          right(nullptr)
    { }

    void insert_left(int value);
    void insert_right(int value);

    int remove_left();
    int remove_right();
};

#endif 