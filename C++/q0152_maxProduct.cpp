// 152. Maximum Product Subarray
// Given an integer array nums, find a contiguous non-empty subarray within the
// array that has the largest product, and return the product.
//
// It is guaranteed that the answer will fit in a 32-bit integer.
//
// A subarray is a contiguous subsequence of the array.

#include "leetcode.h"

using namespace std;

class Solution
{
  public:
    int maxProduct(vector<int> &nums)
    {
        // int size = nums.size();
        // int ret[size];

        // ret_max[0] = nums[0];
        // ret_min[0] = nums[0];

        // int max_ret = ret_max[0];

        // for (int i = 1; i < size; i++)
        // {
        //     if (nums[i] == 0)
        //     {
        //         ret_max[i] = 0;
        //         ret_min[i] = 0;
        //     }
        //     else
        //     {
        //         if (ret_max[i - 1] == 0)
        //         {
        //             ret_max[0] = nums[i];
        //             ret_min[0] = nums[i];
        //         }
        //         else if (nums[i] > 0)
        //         {
        //             retmax[i] = max(nums[i] * ret_max[i - 1], nums[i]);
        //             retmin[i] = nums[i] * ret_min[i - 1];
        //         }
        //         else
        //         {
        //             retmax[i] = nums[i] * ret_min[i - 1];
        //             retmin[i] = min(nums[i] * ret_max[i - 1], nums[i]);
        //         }
        //     }

        //     max_ret = max(max_ret, ret_max[i]);
        // }

        // return max_ret;
    }
};
