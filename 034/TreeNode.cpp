#include "TreeNode.h"

void rotateLeft(TreeNode *&t)
{
    TreeNode *t_right = t->right_;
    TreeNode *t_right_left = t_right->left_;

    t_right->left_ = t;
    t->right_ = t_right_left;

    t = t_right;
}

void rotateRight(TreeNode *&t)
{

    TreeNode *t_left = t->left_;
    TreeNode *t_left_right = t_left->right_;

    t_left->right_ = t;
    t->left_ = t_left_right;

    t = t_left;
}

void rotateLeftRight(TreeNode *&t)
{
    rotateLeft(t->left_);
    rotateRight(t);
}

void rotateRightLeft(TreeNode *&t)
{
    rotateRight(t->right_);
    rotateLeft(t);
}

TreeNode::RotationType balanceTree(TreeNode *&subroot)
{
    // Your code here
    int balance = getHeight(subroot->right_) - getHeight(subroot->left_);
    if (balance == -2)
    {
        int l_balance = getHeight(subroot->left_->right_) - getHeight(subroot->left_->left_);
        if (l_balance == -1)
        {
            rotateRight(subroot);
            return TreeNode::right;
        }
        else
        {
            rotateLeftRight(subroot);
            return TreeNode::leftRight;
        }
    }
    else if (balance == 2)
    {
        int r_balance = getHeight(subroot->right_->right_) - getHeight(subroot->right_->left_);
        if (r_balance == 1)
        {
            rotateLeft(subroot);
            return TreeNode::left;
        }
        else
        {
            rotateRightLeft(subroot);
        }
    }

    return TreeNode::rightLeft;
}