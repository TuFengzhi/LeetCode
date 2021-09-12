// 530. Minimum Absolute Difference in BST
// Given the root of a Binary Search Tree (BST), return the minimum absolute
// difference between the values of any two different nodes in the tree.

#include "pch.h"

using namespace std;

class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        inorderTraversal(root);
        return min_diff;
    }

    int inorderTraversal(TreeNode *root)
    {
        if (!root)
            return 0;
        if (root->left)
            getMinimumDifference(root->left);
        if (is_init == 0)
        {
            last_val = root->val;
            is_init = 1;
        }
        else
        {
            int diff = root->val - last_val;
            if (diff < min_diff)
                min_diff = diff;
            last_val = root->val;
        }
        if (root->right)
            getMinimumDifference(root->right);
        return 0;
    }

private:
    int min_diff = INT_MAX;
    int last_val = 0;
    bool is_init = 0;
};
