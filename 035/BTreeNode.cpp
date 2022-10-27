#include <vector>
#include "BTreeNode.h"

size_t getInsertionIdx(std::vector<int> elements, int key)
{
    for (unsigned long i = 0; i < elements.size(); ++i)
    {
        if (elements[i] > key || elements[i] == key)
            return i;
    }
    return elements.size();
}

BTreeNode *find(BTreeNode *root, int key)
{
    // Your Code Here
    size_t insertion_idx = getInsertionIdx(root->elements_, key);

    if (insertion_idx < root->elements_.size() &&
        root->elements_[insertion_idx] == key)
    {
        return root;
    }

    if (root->is_leaf_)
        return NULL;
    else
        return find(root->children_[insertion_idx], key);
}
