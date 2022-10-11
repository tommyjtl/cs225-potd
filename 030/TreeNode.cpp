#include "TreeNode.h"

int max(int a, int b) { 
  return (a > b) ? a : b; 
};

int getHeight(TreeNode* node)
{
  if (node == NULL)
    return 0;
  return max(getHeight(node->left_), getHeight(node->right_)) + 1;
};

int getHeightBalance(TreeNode* root) {
  // your code here
  return getHeight(root->left_) - getHeight(root->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

