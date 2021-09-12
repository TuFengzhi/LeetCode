// 404. Sum of Left Leaves
// Given the root of a binary tree, return the sum of all left leaves.

#include "pch.h"

using namespace std;

class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int sum = 0;

        if (root->left)
            sum += helper(root->left, root);
        if (root->right)
            sum += helper(root->right, root);
        return sum;
    }

private:
    int helper(TreeNode *root, TreeNode *prev)
    {
        int sum = 0;
        if (!root->left && !root->right)
        {
            if (prev->left == root)
                return root->val;
            else
                return 0;
        }
        if (root->left)
        {
            sum += helper(root->left, root);
        }
        if (root->right)
        {
            sum += helper(root->right, root);
        }
        return sum;
    }
};
