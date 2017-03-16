#include <iostream>
#include "bst.hpp"

using namespace bst;

bool test_insert()
{
    node* n = new node(5);
    n->insert(2);
    n->insert(7);

    return true;
}

bool test_find()
{
    node* n = new node(5);
    n->insert(2);
    n->insert(7);

    node* result = n->find(2);
    return result->getValue() == 2;    
}

bool test_delete()
{
    node* n = new node(5);
    n->insert(2);
    n->insert(7);

    n = n->remove(7);

    return n->find(7) == nullptr;
}

int main()
{
    std::cout << "Insert: " << test_insert() << std::endl;
    std::cout << "Find: " << test_find() << std::endl;;
    std::cout << "Delete: " << test_delete() << std::endl;
}