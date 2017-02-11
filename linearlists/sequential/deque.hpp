#ifndef SEQUENTIAL_DEQUE_HPP
#define SEQUENTIAL_DEQUE_HPP

struct deque 
{
    // The maximum possible size of the deque
    int capacity;

    // The current size of the deque 
    int size;

    // The index one below the left-most element
    int left;
    
    // The index of the right-most element.
    int right;

    // An array to contain the elements
    int* storage;

    deque(int capacity_to_allocate)
      : capacity(capacity_to_allocate),
        size(0),
        left(0),
        right(0),
        storage(new int[capacity])
    { }

    ~deque() {
        delete storage;
    }

    void insert_right(int value);
    void insert_left(int value); 
    int remove_left();
    int remove_right();
};

#endif 