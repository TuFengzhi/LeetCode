// 15. 3Sum
// Given an integer array nums, return all the triplets [nums[i], nums[j],
// nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
// nums[k] == 0.
//
// Notice that the solution set must not contain duplicate triplets.

#include "pch.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int size = nums.size();

        if (size < 3)
            return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> ret;

        for (int i = 0; i < size; i++)
        {
            int target = nums[i];
            vector<vector<int>> ret_i = twoSum(nums, i + 1, -target);

            for (auto &it : ret_i)
            {
                it.push_back(nums[i]);
                ret.push_back(it);
            }
            while ((i < size - 1) && (nums[i + 1] == target))
            {
                i++;
            }
        }
        return ret;
    }

private:
    vector<vector<int>> twoSum(vector<int> &nums, int start, int target)
    {
        vector<vector<int>> ret;
        int left_ptr = start;
        int right_ptr = nums.size() - 1;

        while (left_ptr < right_ptr)
        {
            int left = nums[left_ptr], right = nums[right_ptr];
            int sum = left + right;
            if (sum == target)
            {
                ret.push_back({nums[left_ptr], nums[right_ptr]});
                while ((nums[left_ptr] == left) && left_ptr < right_ptr)
                    left_ptr++;
                while ((nums[right_ptr] == right) && right_ptr > left_ptr)
                    right_ptr--;
            }
            else if (sum > target)
            {
                while ((nums[right_ptr] == right) && right_ptr > left_ptr)
                    right_ptr--;
            }
            else
            {
                while ((nums[left_ptr] == left) && left_ptr < right_ptr)
                    left_ptr++;
            }
        }
        return ret;
    }
};

// TEST(threeSum, Case1)
// {
//     vector<int> nums = {0, 0, 0};
//     Solution s;
//     s.threeSum(nums);
// }
