// 101. Symmetric Tree
// Given the root of a binary tree, check whether it is a mirror of itself
// (i.e., symmetric around its center).

#include "pch.h"

using namespace std;

class Solution
{
public:
    bool traversalTwoTree(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
        {
            return true;
        }
        if (!left || !right)
        {
            return false;
        }
        if (left->val == right->val)
        {
            return traversalTwoTree(left->left, right->right) &&
                   traversalTwoTree(left->right, right->left);
        }

        return false;
    }

    bool isSymmetric(TreeNode *root)
    {
        return traversalTwoTree(root->left, root->right);
    }
};
