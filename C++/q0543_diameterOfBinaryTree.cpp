// 543. Diameter of Binary Tree
// Given the root of a binary tree, return the length of the diameter of the
// tree.
// The diameter of a binary tree is the length of the longest path between any
// two nodes in a tree.This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges
// between them.

#include "leetcode.h"

using namespace std;

class Solution
{
  public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        maxDepth(root);
        return max(max_depth - 1, 0);
    }

  private:
    int max_depth = 0;
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        max_depth = max(max_depth, left_depth + right_depth + 1);
        return max(left_depth, right_depth) + 1;
    }
};
