// 653. Two Sum IV - Input is a BST
// Given the root of a Binary Search Tree and a target number k, return true if
// there exist two elements in the BST such that their sum is equal to the given
// target.

#include "pch.h"

using namespace std;

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        inorderTraversal(root);

        int left_index = 0;
        int right_index = ret.size() - 1;

        while (left_index < right_index)
        {
            int sum = ret[left_index] + ret[right_index];
            if (sum == k)
            {
                return true;
            }
            else if (sum > k)
            {
                right_index--;
            }
            else
            {
                left_index++;
            }
        }

        return false;
    }

private:
    vector<int> ret;

    void inorderTraversal(TreeNode *root)
    {
        if (root)
        {
            inorderTraversal(root->left);
            ret.push_back(root->val);
            inorderTraversal(root->right);
        }
    }
};
