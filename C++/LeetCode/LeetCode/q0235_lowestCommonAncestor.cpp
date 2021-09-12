// 235. Lowest Common Ancestor of a Binary Search Tree
// Given a binary search tree (BST), find the lowest common ancestor (LCA) of
// two given nodes in the BST.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor
// is defined between two nodes p and q as the lowest node in T that has both p
// and q as descendants(where we allow a node to be a descendant of itself).”

#include "pch.h"

using namespace std;

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;

        int max_val = max(p->val, q->val);
        int min_val = min(p->val, q->val);

        if (root->val <= max_val && root->val >= min_val)
        {
            return root;
        }
        else if (root->val < min_val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if (root->val > max_val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};
