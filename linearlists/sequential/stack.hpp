namespace sequential {
    class stack {
        // The maximum permitted size of the stack
        int capacity;

        // The index one above the top element on the stack
        int top;

        // An array in which to store the elements
        int* storage;

    public:

        stack(int capacity_to_allocate) : 
            capacity(capacity_to_allocate), 
            top(0),
            storage(new int[capacity]) 
        { }

        ~stack() {
            delete storage;
        }

        void push(int);
        int pop();
    };
}