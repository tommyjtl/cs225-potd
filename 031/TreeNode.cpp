#include "TreeNode.h"

#include <cmath>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getHeight(TreeNode *node)
{
    if (node == NULL)
        return 0;
    return max(getHeight(node->left_), getHeight(node->right_)) + 1;
}

bool isHeightBalanced(TreeNode *root)
{
    // your code here

    // if root is NULL, it's balanced by nature
    if (root == NULL)
        return true;

    // continue check
    if (std::abs(getHeight(root->left_) - getHeight(root->right_)) <= 1 &&
        isHeightBalanced(root->left_))
        return true;

    // otherwise, false
    return false;
}

void deleteTree(TreeNode *root)
{
    if (root == NULL)
        return;
    deleteTree(root->left_);
    deleteTree(root->right_);
    delete root;
    root = NULL;
}
