// 637. Average of Levels in Binary Tree
// Given the root of a binary tree, return the average value of the nodes on
// each level in the form of an array. Answers within 10-5 of the actual answer
// will be accepted.

#include "pch.h"

using namespace std;

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ret;

        if (!root)
            return ret;

        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty())
        {
            int size = que.size();
            double total_level = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *cur = que.front();
                que.pop();
                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
                total_level += cur->val;
            }
            total_level /= size;
            ret.push_back(total_level);
        }

        return ret;
    }
};
