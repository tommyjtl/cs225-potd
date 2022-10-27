#include <vector>
#include <iostream>
#include "BTreeNode.h"
#include <unistd.h>
#include <algorithm>

unsigned int ms = 0.6 * 1000000;

void traverse(BTreeNode *root, std::vector<int> &v)
{
    if (root->is_leaf_)
    {
        for (unsigned long i = 0; i < root->elements_.size(); i++)
        {
            v.push_back(root->elements_[i]);
            std::cout << "+---------------------------+" << std::endl;
            std::cout << "| v.push_back: " << root->elements_[i] << std::endl;
            std::cout << "+---------------------------+" << std::endl;
            // usleep(ms);
        }
        return;
    }

    size_t idx = 0;
    while (idx < root->children_.size())
    {
        traverse(root->children_[idx], v);
        if (idx < root->elements_.size())
        {
            v.push_back(root->elements_[idx]);
            std::cout << "+---------------------------+" << std::endl;
            std::cout << "| v.push_back: " << root->elements_[idx] << std::endl;
            std::cout << "+---------------------------+" << std::endl;
        }

        idx++;
        // usleep(ms);
    }
}

std::vector<int> traverse(BTreeNode *root)
{
    // your code here
    std::vector<int> v;

    if (root == NULL)
        return v;

    traverse(root, v);

    return v;
}
