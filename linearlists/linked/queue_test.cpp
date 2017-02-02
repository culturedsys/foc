#include <iostream>
#include "queue.hpp"
#include "../errors.hpp"

// Enqueue followed by unqueue returns the value enqueued
bool test_enqueue_unqueue() 
{
    queue q(10);
    q.enqueue(1);
    return q.unqueue() == 1;
}

// Enqueueing two values and then unqueueing returns them in order
bool test_two_enqueue() 
{
    queue q(10);
    q.enqueue(1);
    q.enqueue(2);
    return q.unqueue() == 1 && q.unqueue() == 2;
}

// Enqueing values past the end of the array wraps around
bool test_wrap() 
{
    bool result = true;
    queue q(2);
    q.enqueue(1);
    q.enqueue(2);

    result = result && q.unqueue() == 1;

    q.enqueue(3);

    return result && q.unqueue() == 2 && q.unqueue() == 3;
}

// Enqueing too many values throws
bool test_overflow()
{
    try 
    {
        queue q(2);
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
    }
    catch (error e)
    {
        return e == OVERFLOW;
    }

    return false;
}

// Unqueing from an empty queue throws
bool test_underflow() 
{
    try
    {
        queue q(10);
        q.unqueue();
    }
    catch (error e)
    {
        return e == UNDERFLOW;
    }

    return false;
}

int main()
{
    std::cout << "Enqueue/unqueue: " << test_enqueue_unqueue() << std::endl;
    std::cout << "Two enqueues/unqueues: " << test_two_enqueue() << std::endl;
    std::cout << "Wrap: " << test_wrap() << std::endl;
    std::cout << "Overflow: " << test_overflow() << std::endl;
    std::cout << "Underflow: " << test_underflow() << std::endl;
}