#include "TreeNode.h"

#include <algorithm>
#include <cmath>
#include <iostream>

void rightRotate(TreeNode *root)
{
    /*
    Let P be Q's left child.
    Set Q's left child to be P's right child.
    [Set P's right-child's parent to Q]
    Set P's right child to be Q.
    [Set Q's parent to P]
    */

    TreeNode *root_parent = root->parent_;
    TreeNode *p = root->left_;
    root->left_ = p->right_;

    if (p->right_ != NULL)
        p->right_->parent_ = root;

    p->right_ = root;

    if (root != NULL)
        root->parent_ = p;

    p->parent_ = root_parent;
    if (root_parent != NULL)
        root_parent->left_ = p;

    // TreeNode *t_left = root->left_;
    // TreeNode *t_left_right = t_left->right_;

    // t_left->right_ = root;
    // root->left_ = t_left_right;

    // if (root->parent_ != NULL)
    //   root->parent_->left_ = t_left;
}

void leftRotate(TreeNode *root)
{
    /*
    Let Q be P's right child.
    Set P's right child to be Q's left child.
    [Set Q's left-child's parent to P]
    Set Q's left child to be P.
    [Set P's parent to Q]
    */

    TreeNode *root_parent = root->parent_;
    TreeNode *q = root->right_;
    root->right_ = q->left_;

    if (q->left_ != NULL)
        q->left_->parent_ = root;

    q->left_ = root;

    if (root != NULL)
        root->parent_ = q;

    q->parent_ = root_parent;
    if (root_parent != NULL)
        root_parent->right_ = q;
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