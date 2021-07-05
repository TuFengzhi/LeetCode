// 53. Maximum Subarray
// Given an integer array nums, find the contiguous subarray (containing at
// least one number) which has the largest sum and return its sum.

#include "leetcode.h"

using namespace std;

class Solution
{
  public:
    // Dynamic Programming Solution
    int maxSubArrayDP(vector<int> &nums)
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

    // Divide and Conquer Solution
    int maxSubArray(vector<int> &nums)
    {
        Status ret = dcHelper(nums, 0, nums.size() - 1);

        return ret.m_sum;
    }

  private:
    struct Status
    {
        int l_sum; // max with left node
        int r_sum; // max with right node
        int m_sum; // max sum
        int i_sum; // total sum
    };

    Status merge(Status l, Status r)
    {
        int l_sum = max(l.l_sum, l.i_sum + r.l_sum);
        int r_sum = max(r.r_sum, l.r_sum + r.i_sum);
        int i_sum = l.i_sum + r.i_sum;
        int m_sum = max({l.m_sum, r.m_sum, l.r_sum + r.l_sum});

        return Status{l_sum, r_sum, m_sum, i_sum};
    }

    Status dcHelper(vector<int> &nums, int li, int ri)
    {
        if (li == ri)
        {
            return Status{nums[li], nums[li], nums[li], nums[li]};
        }
        int m = (li + ri) >> 1;
        Status l = dcHelper(nums, li, m);
        Status r = dcHelper(nums, m + 1, ri);

        return merge(l, r);
    }
};
