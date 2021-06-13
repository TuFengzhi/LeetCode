// 112. Path Sum
// Given the root of a binary tree and an integer targetSum, return true if the
// tree has a root-to-leaf path such that adding up all the values along the
// path equals targetSum. A leaf is a node with no children.

#include "leetcode.h"

using namespace std;

class Solution
{
  public:
    bool helper(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return false;
        }
        if (!root->left && !root->right)
        {
            if (targetSum == root->val)
                return true;
            else
                return false;
        }
        else
        {
            targetSum -= root->val;
            return helper(root->left, targetSum) ||
                   helper(root->right, targetSum);
        }
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        return helper(root, targetSum);
    }
};
