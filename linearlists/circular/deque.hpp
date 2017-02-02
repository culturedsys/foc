#ifndef CIRCULAR_DEQUE_HPP
#define CIRCULAR_DEQUE_HPP

#include "../linked/nodes.hpp"

class deque
{
    node_allocator allocator;
    node* ptr;

public:
    deque(int capacity);

    void insert_left(int value);
    int remove_left();

    void insert_right(int value);
    int remove_right();
};

#endif