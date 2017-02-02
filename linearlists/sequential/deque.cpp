/*
 * An implementation of the deque data structure in terms of sequential
 * memory. Specifically, uses a circular buffer.
 */
#include <iostream>
#include "../errors.hpp"

#include "deque.hpp"

// Insert value at the right of the deque
void deque::insert_right(int value) 
{
    if (size == capacity) {
        throw OVERFLOW;
    }
    size++;
    if (right == capacity - 1) {
        right = 0;
    } else {
        right++;
    }
    storage[right] = value;
}

// Insert value at the left of the deque
void deque::insert_left(int value) 
{
    if (size == capacity) {
        throw OVERFLOW;
    }
    size++;
    storage[left] = value;
    if (left == 0) {
        left = capacity - 1;
    } else {
        left--;
    }
}

// Remove the value at the left of the deque, and return it
int deque::remove_left() 
{
    if (size == 0) {
        throw UNDERFLOW;
    }
    size--;

    if (left == capacity - 1) {
        left = 0;
    } else {
        left++;
    }
    return storage[left];
}

// Remove the value at the right of the deque, and return it
int deque::remove_right() 
{
    if (size == 0) {
        throw UNDERFLOW;
    }
    size--;

    int result = storage[right];

    if (right == 0) {
        right = capacity - 1;
    } else {
        right--;
    }

    return result;
}

