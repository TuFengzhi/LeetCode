// 169. Majority Element
//
// Given an array nums of size n, return the majority element.
//
// The majority element is the element that appears more than ⌊ n / 2 ⌋ times.
// You may assume that the majority element always exists in the array.

#include "leetcode.h"

using namespace std;

class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        int size = nums.size();
        while (true)
        {
            int candidate = nums[rand() % size];
            int count = 0;
            for (auto num : nums)
                if (candidate == num)
                    count++;
            if (count > size / 2)
            {
                return candidate;
            }
        }

        return -1;
    }
};
