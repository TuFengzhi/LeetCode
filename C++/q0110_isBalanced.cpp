// 110. Balanced Binary Tree
// Given a binary tree, determine if it is height-balanced.
// For this problem, a height - balanced binary tree is defined as : a binary
// tree in which the left and right subtrees of every node differ in height by
// no more than 1.

#include "leetcode.h"

using namespace std;

class Solution
{
  public:
    bool helper(TreeNode *root, int *ret_height)
    {
        if (!root)
        {
            *ret_height = 0;
            return true;
        }
        int left_height = 0;
        int right_height = 0;
        if (helper(root->left, &left_height) &&
            helper(root->right, &right_height))
        {
            if (abs(left_height - right_height) <= 1)
            {
                *ret_height = max(left_height, right_height) + 1;
                return true;
            }
        }

        return false;
    }
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;

        int left_height = 0;
        int right_height = 0;
        if (helper(root->left, &left_height) &&
            helper(root->right, &right_height))
        {
            if (abs(left_height - right_height) <= 1)
            {
                return true;
            }
        }

        return false;
    }
};
