#ifndef SEQUENTIAL_QUEUE
#define SEQUENTIAL_QUEUE

#include "../errors.hpp"

struct queue 
{
    // The maximum permitted number of elements in the queue
    int capacity;

    // The current number of elements
    int size;

    // The index one below the element at the front of the queue
    int front;

    // The index of the element at the rear of the queue
    int rear;

    // An array to store the elements of the queue
    int* storage;

    queue(int capacity_to_allocate)
      : capacity(capacity_to_allocate),
        size(0),
        front(0),
        rear(0),
        storage(new int[capacity])
    { }

    ~queue() {
        delete storage;
    }

    void enqueue(int value); 
    int unqueue();
};

#endif