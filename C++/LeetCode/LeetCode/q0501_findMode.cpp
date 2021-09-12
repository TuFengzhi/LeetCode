// 501. Find Mode in Binary Search Tree
// Given the root of a binary search tree (BST) with duplicates, return all the
// mode(s) (i.e., the most frequently occurred element) in it.
// If the tree has more than one mode, return them in any order.
// Assume a BST is defined as follows:
// * The left subtree of a node contains only nodes with keys less than or equal
// to the node's key.
// * The right subtree of a node contains only nodes with keys greater than or
// equal to the node's key.
// * Both the left and right subtrees must also be binary search trees.

#include "pch.h"

using namespace std;

class Solution
{
public:
    int ret_val = INT_MIN;
    int ret_size = 0;
    int cur_val = INT_MIN;
    int cur_size = 0;
    vector<int> ret;

    vector<int> findMode(TreeNode *root)
    {
        inorderTraversal(root);

        if (cur_size > ret_size)
        {
            ret_val = cur_val;
            ret_size = cur_size;
            ret.clear();
            ret.push_back(ret_val);
        }
        else if (cur_size == ret_size)
        {
            ret_val = cur_val;
            ret_size = cur_size;
            ret.push_back(ret_val);
        }

        return ret;
    }

    int inorderTraversal(TreeNode *root)
    {
        if (!root)
            return 0;

        if (root->left)
            inorderTraversal(root->left);
        if (root->val > cur_val)
        {
            if (cur_size > ret_size)
            {
                ret_val = cur_val;
                ret_size = cur_size;
                ret.clear();
                ret.push_back(ret_val);
            }
            else if (cur_size == ret_size)
            {
                ret_val = cur_val;
                ret_size = cur_size;
                ret.push_back(ret_val);
            }
            cur_val = root->val;
            cur_size = 1;
        }
        else if (root->val == cur_val)
        {
            cur_size++;
        }
        if (root->right)
            inorderTraversal(root->right);

        return 0;
    }
};
