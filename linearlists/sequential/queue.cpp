/*
 * An implementation of the queue data structure in terms of sequential
 * memory, using a circular buffer
 */

#include <iostream>
#include "queue.hpp"

// Add value at the rear of the queue
void queue::enqueue(int value) 
{
    if (size == capacity) {
        throw OVERFLOW;
    }
    size++;
    if (rear == capacity - 1) {
        rear = 0;
    } else {
        rear++;
    }
    storage[rear] = value;
}

// Remove the value at the front of the queue, and return it
int queue::unqueue() 
{
    if (size == 0) {
        throw UNDERFLOW;
    }
    size--;

    if (front == capacity - 1) {
        front = 0;
    } else {
        front++;
    }

    return storage[front];
}

