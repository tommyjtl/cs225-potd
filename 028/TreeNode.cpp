#include "TreeNode.h"
#include <iostream>

TreeNode *findMinimum(TreeNode *subtree)
{
    TreeNode *min = subtree;
    while (min && min->left_ != NULL)
        min = min->left_;
    return min;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    // your code here
    if (root == NULL)
        return root;

    if (key < root->val_)
        root->left_ = deleteNode(root->left_, key);
    else if (key > root->val_)
        root->right_ = deleteNode(root->right_, key);
    else
    {
        if (root->left_ == NULL)
        {
            TreeNode *temp = root->right_;
            delete root;
            return temp;
        }
        else if (root->right_ == NULL)
        {
            TreeNode *temp = root->left_;
            delete root;
            return temp;
        }
        TreeNode *temp = findMinimum(root->right_);
        root->val_ = temp->val_;
        root->right_ = deleteNode(root->right_, temp->val_);
    }
    return root;
}

void inorderPrint(TreeNode *node)
{
    if (!node)
        return;
    inorderPrint(node->left_);
    std::cout << node->val_ << " ";
    inorderPrint(node->right_);
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
