#include "TreeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left_(NULL), right_(NULL) {}

int TreeNode::getHeight()
{
    if (left_ == NULL && right_ == NULL)
        return 0;

    int left_height = 0;
    int right_height = 0;

    if (left_ != NULL && right_ == NULL)
    {
        left_height++;
        left_height += left_->getHeight();
    }
    else if (left_ == NULL && right_ != NULL)
    {
        right_height++;
        right_height += right_->getHeight();
    }
    else if (left_ != NULL && right_ != NULL)
    {
        left_height++;
        right_height++;
        left_height += left_->getHeight();
        right_height += right_->getHeight();
    }

    if (left_height > right_height)
        return left_height;

    return right_height;
}
