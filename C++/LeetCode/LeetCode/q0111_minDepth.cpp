// 111. Minimum Depth of Binary Tree
// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the
// root node down to the nearest leaf node.
// Note : A leaf is a node with no children.

#include "pch.h"

using namespace std;

class Solution
{
public:
    int helper(TreeNode *root)
    {
        if (!root)
            return INT_MAX;
        if (!root->left && !root->right)
            return 1;

        return min(helper(root->left), helper(root->right)) + 1;
    }
    int minDepth1(TreeNode *root)
    {
        if (!root)
            return 0;

        return helper(root);
    }
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int min_depth = 0;

        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty())
        {
            min_depth++;
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *cur = que.front();
                que.pop();
                if (!cur->left && !cur->right)
                    return min_depth;
                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
        }

        return min_depth;
    }
};
