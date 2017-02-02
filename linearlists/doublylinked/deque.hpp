#ifndef DOUBLYLINKED_DEQUE_HPP
#define DOUBLYLINKED_DEQUE_HPP

#include "../allocator.hpp"

struct node
{
    int value;
    node* prev;
    node* next;
};

class deque
{
    node_allocator<node> allocator;
    node* left;
    node* right;

public:
    deque(int);

    void insert_left(int);
    int remove_left();

    void insert_right(int);
    int remove_right();
};

#endif