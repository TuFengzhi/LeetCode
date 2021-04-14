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

bool isValidBSTWithMaxMin(struct TreeNode *root, long int max_val,
                          long int min_val)
{
    if (root == NULL)
        return true;

    if ((root->val >= max_val) || (root->val <= min_val))
        return false;

    return (isValidBSTWithMaxMin(root->left, root->val, min_val) &&
            isValidBSTWithMaxMin(root->right, max_val, root->val));
}

bool isValidBST(struct TreeNode *root)
{
    if (root == NULL)
        return true;

    return isValidBSTWithMaxMin(root, LONG_MAX, LONG_MIN);
}

#if defined(Q0098)

CTEST(Q0098isValidBST, Case1) {}

#endif
