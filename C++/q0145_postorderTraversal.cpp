// 145. Binary Tree Postorder Traversal
// Given the root of a binary tree, return the postorder traversal of its nodes'
// values.

#include "leetcode.h"

using namespace std;

class Solution
{
  public:
    vector<int> postorderTraversalRecursion(TreeNode *root)
    {
        vector<int> ret;
        if (!root)
            return ret;
        ret = postorderTraversalRecursion(root->left);
        vector<int> right = postorderTraversalRecursion(root->right);
        ret.insert(ret.end(), right.begin(), right.end());
        ret.push_back(root->val);

        return ret;
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        if (!root)
            return ret;

        TreeNode *prev = root;
        TreeNode *cur = root;

        stack<TreeNode *> sta;

        while (!sta.empty() || cur != NULL)
        {
            while (cur)
            {
                sta.emplace(cur);
                cur = cur->left;
            }

            cur = sta.top();
            sta.pop();

            if (cur->right == NULL || prev == cur->right)
            {
                ret.push_back(cur->val);
                prev = cur;
                cur = NULL;
            }
            else
            {
                sta.emplace(cur);
                cur = cur->right;
            }
        }

        return ret;
    }
};

// TEST(postorderTraversal, Case1)
// {
//     TreeNode t1 = TreeNode(1);
//     TreeNode t2 = TreeNode(2);
//     TreeNode t3 = TreeNode(3);
//     t1.left = NULL;
//     t1.right = &t2;
//     t2.left = &t3;
//     t2.right = NULL;
//     Solution s;
//     s.postorderTraversal(&t1);
// }
