// 617. Merge Two Binary Trees
// You are given two binary trees root1 and root2.
//
// Imagine that when you put one of them to cover the other, some nodes of the
// two trees are overlapped while the others are not .You need to merge the two
// trees into a new binary tree.The merge rule is that if two nodes overlap,
// then sum node values up as the new value of the merged node. Otherwise, the
// NOT null node will be used as the node of the new tree.
//
// Return the merged tree.
// Note : The merging process must start from the root nodes of both trees.

#include "leetcode.h"

using namespace std;

class Solution
{
  public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
        {
            return NULL;
        }

        if (root1 && root2)
        {
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
            return root1;
        }

        if (root1)
        {
            return root1;
        }

        if (root2)
        {
            return root2;
        }

        return NULL;
    }
};
