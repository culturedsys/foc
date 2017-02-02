#include <iostream>

#include "stack.hpp"
#include "../errors.hpp"

using namespace linked;

// A push followed by a pop returns the value pushed
bool test_push_pop() {
    stack s(10);
    s.push(1);
    return s.pop();
}


// Two pushes followed by two pops returns the numbers in reverse order.
bool test_two_pushes() {
    stack s(10);
    s.push(1);
    s.push(2);

    return s.pop() == 2 && s.pop() == 1;
}

// A push which takes the stack over capacity throws
bool test_overflow() {
    try {
        stack s(1);
        s.push(1);
        s.push(2);
    } catch (error e) {
        return e == OVERFLOW;
    }

    return false;
}

// Pop on an empty stack throws
bool test_underflow() {
    try {
        stack s(10);
        s.pop();
    } catch (error e) {
        return e == UNDERFLOW;
    }

    return false;
}

int main() {
    std::cout << "Push/pop: " << test_push_pop() << std::endl;
    std::cout << "Two pushes, two pops: " << test_two_pushes() << std::endl;
    std::cout << "Overflow: " << test_overflow() << std::endl;
    std::cout << "Underflow: " << test_underflow() << std::endl;
}