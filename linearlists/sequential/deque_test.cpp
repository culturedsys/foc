#include <iostream>
#include "../errors.hpp"
#include "deque.hpp"


// Adding a value at the right and removing a value at the left returns that
// value
bool test_right_left() 
{
    deque q(10);
    q.insert_right(1);
    return q.remove_left() == 1;
}

// Adding a value at the left and removing a value at the right returns that
// value
bool test_left_right() 
{
    deque q(10);
    q.insert_left(1);
    return q.remove_right() == 1;
}

// Adding a value at the left and removing a value at the left returns that
// value
bool test_left_left() 
{
    deque q(10);
    q.insert_left(1);
    return q.remove_left() == 1;
}

// Adding a value at the right and removing a value at the right returns that
// value
bool test_right_right() 
{
    deque q(10);
    q.insert_right(1);
    return q.remove_right() == 1;
}

// Adding two values at the right and removing them from the left returns them
// in order
bool test_two_right_left() 
{
    deque q(10);
    q.insert_right(1);
    q.insert_right(2);
    return q.remove_left() == 1 && q.remove_left() == 2;
}

// Adding two value at the left and removing them from the right returns them
// in order
bool test_two_left_right() 
{
    deque q(10);
    q.insert_left(1);
    q.insert_left(2);
    return q.remove_right() == 1 && q.remove_right() == 2;
}

// Adding two values at the left and removing them from the left returns them
// in reverse order
bool test_two_left_left() 
{
    deque q(10);
    q.insert_left(1);
    q.insert_left(2);
    return q.remove_left() == 2 && q.remove_left() == 1;
}

// Adding two value at the right and removing them from the right returns them
// in reverse order
bool test_two_right_right() 
{
    deque q(10);
    q.insert_right(1);
    q.insert_right(2);
    return q.remove_right() == 2 && q.remove_right() == 1;
}

// Wrap around when reaching the end of storage inserting to the right
bool test_wrap_right() 
{
    bool result = true;
    deque q(2);
    q.insert_right(1);
    q.insert_right(2);

    result = result && q.remove_left() == 1;

    q.insert_right(3);

    return result && q.remove_left() == 2 && q.remove_left() == 3;
}

// Wrap around when reaching the beginning of storage inserting to the left
bool test_wrap_left() 
{
    deque q(2);
    q.insert_left(1);
    q.insert_left(2);

    bool result = q.remove_right() == 1;

    q.insert_left(3);

    return result && q.remove_right() == 2 && q.remove_right() == 3;
}

// Overflow when adding too many elements to the right
bool test_overflow_right()
{
    try 
    {
        deque q(2);
        q.insert_right(1);
        q.insert_right(2);
        q.insert_right(3);
    } 
    catch (error e) 
    {
        return e == OVERFLOW;
    }

    return false;
}

// Overflow when adding too many elements to the left
bool test_overflow_left()
{
    try 
    {
        deque q(2);
        q.insert_left(1);
        q.insert_left(2);
        q.insert_left(3);
    } 
    catch (error e) 
    {
        return e == OVERFLOW;
    }

    return false;
}

// Underflow when removing from the left of an empty deque
bool test_underflow_left() 
{
    try
    {
        deque q(10);
        q.remove_left();
    }
    catch (error e)
    {
        return e == UNDERFLOW;
    }

    return false;
}

// Underflow when removing from the right of an empty deque
bool test_underflow_right() 
{
    try
    {
        deque q(10);
        q.remove_right();
    }
    catch (error e)
    {
        return e == UNDERFLOW;
    }

    return false;
}

int main()
{
    std::cout << "Insert right / remove left: " << test_right_left() << std::endl;
    std::cout << "Insert left / remove right: " << test_left_right() << std::endl;
    std::cout << "Insert right / remove right: " << test_right_right() << std::endl;
    std::cout << "Insert left / remove left: " << test_left_left() << std::endl;
    std::cout << "Two insert right / remove left: " << test_two_right_left() << std::endl;
    std::cout << "Two insert left / remove right: " << test_two_left_right() << std::endl;
    std::cout << "Two insert left / remove left: " << test_two_left_left() << std::endl;
    std::cout << "Two insert right / remove right: " << test_two_right_right() << std::endl;
    std::cout << "Wrap right: " << test_wrap_right() << std::endl;
    std::cout << "Wrap left: " << test_wrap_left() << std::endl;
    std::cout << "Overflow right: " << test_overflow_right() << std::endl;
    std::cout << "Overflow left: " << test_overflow_left() << std::endl;
    std::cout << "Underflow left: " << test_underflow_left() << std::endl;
    std::cout << "Underflow right: " << test_underflow_right() << std::endl;
}