// 26. Remove Duplicates from Sorted Array
//
// Given an integer array nums sorted in non-decreasing order, remove the
// duplicates in-place such that each unique element appears only once. The
// relative order of the elements should be kept the same.
//
// Since it is impossible to change the length of the array in some languages,
// you must instead have the result be placed in the first part of the array
// nums. More formally, if there are k elements after removing the duplicates,
// then the first k elements of nums should hold the final result. It does not
// matter what you leave beyond the first k elements.
//
// Return k after placing the final result in the first k slots of nums.
//
// Do not allocate extra space for another array. You must do this by modifying
// the input array in-place with O(1) extra memory.

#include "pch.h"

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int size = nums.size();
        if (size <= 1)
            return size;
        int slow = 1;
        for (int i = 1; i < size; i++)
        {
            if (nums[i] != nums[slow - 1])
            {
                if (slow != i)
                    // swap(&nums[i], &nums[slow]);
                    // May not swap the number
                    nums[slow] = nums[i];
                slow++;
            }
        }

        return slow;
    }

private:
    void swap(int *x, int *y)
    {
        *x = *x ^ *y;
        *y = *x ^ *y;
        *x = *x ^ *y;
    }
};

// TEST(removeDuplicates, Case1)
// {
//     vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
//     Solution s;
//     s.removeDuplicates(nums);
// }
