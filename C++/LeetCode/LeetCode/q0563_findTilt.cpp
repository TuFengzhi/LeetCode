// 563. Binary Tree Tilt
// Given the root of a binary tree, return the sum of every tree node's tilt.
// The tilt of a tree node is the absolute difference between the sum of all
// left subtree node values and all right subtree node values.If a node does not
// have a left child, then the sum of the left subtree node values is treated as
// 0. The rule is similar if there the node does not have a right child.

#include "pch.h"

using namespace std;

class Solution
{
public:
  int findTilt(TreeNode *root)
  {
    sumOfTree(root);

    return tilt;
  }

private:
  int tilt = 0;
  int sumOfTree(TreeNode *root)
  {
    if (!root)
      return 0;
    int l = sumOfTree(root->left);
    int r = sumOfTree(root->right);

    tilt += abs(l - r);

    return l + r + root->val;
  }
};
