// 108. Convert Sorted Array to Binary Search Tree
// Given an integer array nums where the elements are sorted in ascending order,
// convert it to a height-balanced binary search tree.
// A height - balanced binary tree is a binary tree in which the depth of the
// two subtrees of every node never differs by more than one.

#include "leetcode.h"

using namespace std;

class Solution
{
  public:
    TreeNode *sortedArrayToBSTWithSize(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return NULL;
        int ceter_index = (right + left + 1) / 2;
        TreeNode *ret = new TreeNode(nums[ceter_index]);
        ret->left = sortedArrayToBSTWithSize(nums, left, ceter_index - 1);
        ret->right = sortedArrayToBSTWithSize(nums, ceter_index + 1, right);
        return ret;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBSTWithSize(nums, 0, nums.size() - 1);
    }
};
