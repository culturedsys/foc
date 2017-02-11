/*
 * Allocate an area of memory to use for linked list nodes
 */

#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include "errors.hpp"

template<typename T>
class node_allocator {
    // The total number of nodes that can be allocated
    int capacity;

    // The chunk of memory allocated to store nodes
    T* storage;

    // The number of nodes that have been allocated
    int allocated;

    // The head of the list of available nodes.
    T* avail;

public:

    node_allocator(int capacity)
     :  capacity(capacity),
        storage(new T[capacity]),
        allocated(0),
        avail(nullptr)
    { }

    ~node_allocator();

    // Return an unused node, or throw OVERFLOW if no space left
    T* get_node();

    // Add the node back to the unused list
    void release(T* n);
};

template<typename T>
inline node_allocator<T>::~node_allocator() 
{
    delete storage;
}

// Return an unused node, or throw OVERFLOW if no space left
template<typename T>
inline T* node_allocator<T>::get_node() 
{
    if (avail == nullptr)
    {
        if (allocated == capacity) 
        {
            throw OVERFLOW;
        }
        
        T* result = &storage[allocated];
        result->next = nullptr;

        allocated++;

        return result;
    }

    T* result = avail;
    avail = avail->next;
    return result;
}

// Add the node back to the unused list
template<typename T>
inline void node_allocator<T>::release(T* n)
{
    if (avail == nullptr)
    {
        avail = n;
        avail->next = nullptr;
        return;
    }

    n->next = avail;
    avail = n;
}

#endif