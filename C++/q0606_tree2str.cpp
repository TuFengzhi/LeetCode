// 606. Construct String from Binary Tree
// Given the root of a binary tree, construct a string consists of parenthesis
// and integers from a binary tree with the preorder traversing way, and return
// it.
// Omit all the empty parenthesis pairs that do not affect the one-to-one
// mapping relationship between the string and the original binary tree.

#include "leetcode.h"

using namespace std;

class Solution
{
  public:
    string tree2str(TreeNode *root)
    {
        if (!root)
            return string();

        string ret = to_string(root->val);
        if (root->left)
        {
            ret += "(" + tree2str(root->left) + ")";
        }
        else if (root->right)
        {
            ret += "()";
        }
        if (root->right)
        {
            ret += "(" + tree2str(root->right) + ")";
        }

        return ret;
    }
};
