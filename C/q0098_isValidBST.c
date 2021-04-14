// 98. Validate Binary Search Tree
// A valid BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's
// key. The right subtree of a node contains only nodes with keys greater than
// the node's key. Both the left and right subtrees must also be binary search
// trees.

#include "ctest.h"
#include "leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isValidBST(struct TreeNode *root)
{
    if (root == NULL)
        return true;

    if (root->left)
    {
        if (isValidBST(root->left))
        {
            struct TreeNode *left_right = root->left;
            while (left_right->right)
                left_right = left_right->right;
            if (root->val <= left_right->val)
                return false;
        }
        else
        {
            return false;
        }
    }

    if (root->right)
    {
        if (isValidBST(root->right) && (root->val < root->right->val))
        {
            struct TreeNode *right_left = root->right;
            while (right_left->left)
                right_left = right_left->left;
            if (root->val >= right_left->val)
                return false;
        }
        else
        {
            return false;
        }
    }

    return true;
}

#if defined(Q0098)

CTEST(Q0098isValidBST, Case1) {}

#endif
