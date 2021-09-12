// 152. Maximum Product Subarray
// Given an integer array nums, find a contiguous non-empty subarray within the
// array that has the largest product, and return the product.
//
// It is guaranteed that the answer will fit in a 32-bit integer.
//
// A subarray is a contiguous subsequence of the array.

#include "pch.h"

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int size = nums.size();

        int last_max = nums[0];
        int last_min = nums[0];
        int max_ret = nums[0];

        for (int i = 1; i < size; i++)
        {
            if (nums[i] < 0)
            {
                last_max = last_max ^ last_min;
                last_min = last_max ^ last_min;
                last_max = last_max ^ last_min;
            }

            last_max = max(nums[i], last_max * nums[i]);
            last_min = min(nums[i], last_min * nums[i]);

            max_ret = max(max_ret, last_max);
        }

        return max_ret;
    }
};
