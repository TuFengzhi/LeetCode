// 572. Subtree of Another Tree
// Given the roots of two binary trees root and subRoot, return true if there is
// a subtree of root with the same structure and node values of subRoot and
// false otherwise.
// A subtree of a binary tree tree is a tree that consists of a node in tree and
// all of this node's descendants. The tree tree could also be considered as a
// subtree of itself.

#include "leetcode.h"

using namespace std;

class Solution
{
  public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return false;
        if (isSame(root, subRoot))
            return true;
        else
        {
            if (isSubtree(root->left, subRoot) ||
                isSubtree(root->right, subRoot))
                return true;
            else
                return false;
        }

        return false;
    }

  private:
    bool isSame(TreeNode *x, TreeNode *y)
    {
        if (!x && !y)
        {
            return true;
        }
        else if (x && y)
        {
            if (x->val == y->val)
            {
                if (isSame(x->left, y->left) && isSame(x->right, y->right))
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else
        {
            return false;
        }

        return false;
    }
};
