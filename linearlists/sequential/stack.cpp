/*
 * An implementation of the stack structure using sequential areas of memory.
 */

#include "stack.hpp" 
#include "../errors.hpp"

using namespace sequential;

// Insert value on the stack
void stack::push(int value) {
    if (top == capacity) {
        throw OVERFLOW;
    }

    storage[top] = value;
    top++;
}

// Remove the value from the top of the stack, and return it
int stack::pop() {
    if (top == 0) {
        throw UNDERFLOW;
    }
    int result = storage[top - 1];
    top--;
    return result;
}