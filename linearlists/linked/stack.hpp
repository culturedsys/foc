#ifndef LINKED_STACK_HPP
#define LINKED_STACK_HPP

#include "../allocator.hpp"
#include "node.hpp"

namespace linked {
    class stack
    {
        node* top;
        node_allocator<node> allocator;

    public:

        // Create a stack with the specified maximum size
        stack(int);

        // Add the specified value to the stop of the stack
        void push(int);

        // Remove the value at the top of the stack and return it
        int pop();
    };
}

#endif