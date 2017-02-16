#include "threaded.hpp"

#include <vector>
#include <iostream>

using namespace threaded;

class addto
{
    std::vector<int>& data;
public:
    addto(std::vector<int>& data)
    : data(data)
    { }

    void operator()(int i)
    {
        std::cout << i << std::endl;
        data.push_back(i);
    }
};

bool test_preorder(node* root) 
{
    std::vector<int> results;
    root->traverse_preorder(addto(results));
    std::vector<int> expected = {1, 2, 4, 3, 5, 7, 6, 8, 9};
    return results == expected;
}

bool test_inorder(node* root)
{
    std::vector<int> results;
    root->traverse_inorder(addto(results));
    std::vector<int> expected = {4, 2, 1, 5, 7, 3, 8, 6, 9};

    return results == expected;
}

int main()
{
    node* tree = new node();
    node* root = tree->insert_left(1);
    root->insert_left(2)->insert_left(4);

    node* r1 = root->insert_right(3);
    r1 -> insert_left(5)->insert_right(7);

    node* r2 = r1->insert_right(6);
    r2->insert_left(8);
    r2->insert_right(9);

    std::cout << "Preorder: " << test_preorder(tree) << std::endl;
    std::cout << "Inorder: " << test_inorder(tree) << std::endl;
    delete tree;
}