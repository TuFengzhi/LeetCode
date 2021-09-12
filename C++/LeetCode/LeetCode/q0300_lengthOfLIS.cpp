// 300. Longest Increasing Subsequence
// Given an integer array nums, return the length of the longest strictly
// increasing subsequence.
//
// A subsequence is a sequence that can be derived from an array by deleting
// some or no elements without changing the order of the remaining elements. For
// example, [3, 6, 2, 7] is a subsequence of the array [0, 3, 1, 6, 2, 2, 7].

#include "pch.h"

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int size = nums.size();
        int max_ret = 1;
        vector<pair<int, int>> dp(size);

        dp[0] = make_pair(nums[0], 1);

        for (int i = 1; i < size; i++)
        {
            int cur_max = 1;
            for (int j = 0; j < i; j++)
            {
                if (dp[j].first < nums[i])
                    cur_max = max(cur_max, dp[j].second + 1);
            }
            dp[i] = make_pair(nums[i], cur_max);
            max_ret = max(max_ret, cur_max);
        }

        return max_ret;
    }
};
