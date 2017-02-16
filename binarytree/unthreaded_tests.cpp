#include "unthreaded.hpp"

#include <vector>
#include <iostream>

using namespace unthreaded;

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
    node* tree =
        new node(1, 
            new node(2, 
                new node(4, nullptr, nullptr),
                nullptr
            ),
            new node(3,
                new node(5,
                    nullptr,
                    new node(7, nullptr, nullptr)
                ),
                new node(6,
                    new node(8, nullptr, nullptr),
                    new node(9, nullptr, nullptr)
                )
            )
        );

    std::cout << "Preorder: " << test_preorder(tree) << std::endl;
    std::cout << "Inorder: " << test_inorder(tree) << std::endl;
    delete tree;
}