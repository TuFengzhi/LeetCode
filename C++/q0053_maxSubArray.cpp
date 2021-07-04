// 53. Maximum Subarray
// Given an integer array nums, find the contiguous subarray (containing at
// least one number) which has the largest sum and return its sum.

#include "leetcode.h"

using namespace std;

class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = nums[0];
        int current_sum = 0;
        for (auto &e : nums)
        {
            current_sum = max(current_sum + e, e);
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }

    // TODO: Add Divide and Conquer Solution
    int maxSubArrayDC(vector<int> &nums)
    {
        int max_sum = nums[0];
        int current_sum = 0;
        for (auto &e : nums)
        {
            current_sum = max(current_sum + e, e);
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};
