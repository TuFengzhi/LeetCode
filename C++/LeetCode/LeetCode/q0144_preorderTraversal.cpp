// 144. Binary Tree Preorder Traversal
// Given the root of a binary tree, return the preorder traversal of its nodes'
// values.

#include "pch.h"

using namespace std;

class Solution
{
public:
    vector<int> preorderTraversalRecursion(TreeNode *root)
    {
        vector<int> ret;
        if (!root)
            return ret;
        ret.push_back(root->val);
        vector<int> left = preorderTraversalRecursion(root->left);
        ret.insert(ret.end(), left.begin(), left.end());
        vector<int> right = preorderTraversalRecursion(root->right);
        ret.insert(ret.end(), right.begin(), right.end());

        return ret;
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        if (!root)
            return ret;
        stack<TreeNode *> sta;
        sta.push(root);
        while (!sta.empty())
        {
            TreeNode *cur = sta.top();
            sta.pop();
            ret.push_back(cur->val);

            if (cur->right)
                sta.push(cur->right);

            cur = cur->left;

            while (cur)
            {
                ret.push_back(cur->val);

                if (cur->right)
                    sta.push(cur->right);
                cur = cur->left;
            }
        }

        return ret;
    }
};
