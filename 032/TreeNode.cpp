#include "TreeNode.h"

#include <cmath>
#include <iostream>

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

void inOrderTraversal(TreeNode *root, int level,
                      TreeNode *&lastUnbalanced, int &lastUnbalanced_level)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left_, level + 1, lastUnbalanced, lastUnbalanced_level);
    // std::cout << __LINE__ << ": " << root->val_ << " > " << level << std::endl;
    if (!isHeightBalanced(root) && level >= lastUnbalanced_level)
    {
        lastUnbalanced = root;
        lastUnbalanced_level = level;
    }
    // std::cout << __LINE__ << ": " << root->val_ << " > " << level << std::endl;
    inOrderTraversal(root->right_, level + 1, lastUnbalanced, lastUnbalanced_level);
}

TreeNode *findLastUnbalanced(TreeNode *root)
{
    // your code here
    TreeNode *lastUnbalanced = NULL;
    int lastUnbalanced_level = 0;

    inOrderTraversal(root, 0, lastUnbalanced, lastUnbalanced_level);
    // std::cout << __LINE__ << ": " << lastUnbalanced << std::endl;

    return lastUnbalanced;
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