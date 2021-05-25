// 665. Non-decreasing Array
// Given an array nums with n integers, your task is to check if it could become
// non-decreasing by modifying at most one element.
//
// We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for
// every i (0-based) such that (0 <= i <= n - 2).

#include "ctest.h"
#include "leetcode.h"

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

bool checkPossibility(int *nums, int numsSize)
{
    if (numsSize == 0 || numsSize == 1)
    {
        return true;
    }

    int times = 0;

    int new_array[numsSize + 2];
    memcpy(new_array + 1, nums, numsSize * sizeof(int));
    new_array[0] = min(nums[0], nums[1]);
    new_array[numsSize + 1] = max(nums[numsSize - 1], nums[numsSize - 2]);

    for (int i = 1; i < numsSize; i++)
    {
        if (new_array[i] > new_array[i + 1])
        {
            times++;
            if (((new_array[i - 1] <= new_array[i + 1]) &&
                 (new_array[i + 1] <= new_array[i + 2])) ||
                (new_array[i] <= new_array[i + 2]))
            {
                i++;
            }
            else
            {
                return false;
            }
        }
    }

    if (times < 2)
    {
        return true;
    }

    return false;
}

#if defined(Q0665)

CTEST(Q0665CheckPossibility, Case1)
{
    int arr[] = {4, 2, 3};
    ASSERT_EQUAL(true, checkPossibility(arr, 3));
}

CTEST(Q0665CheckPossibility, Case2)
{
    int arr[] = {4, 2, 1};
    ASSERT_EQUAL(false, checkPossibility(arr, 3));
}

CTEST(Q0665CheckPossibility, Case3)
{
    int arr[] = {4, 6, 7, 6, 5};
    ASSERT_EQUAL(false, checkPossibility(arr, 5));
}

CTEST(Q0665CheckPossibility, Case4)
{
    int arr[] = {3, 4, 2, 3};
    ASSERT_EQUAL(false, checkPossibility(arr, 4));
}

CTEST(Q0665CheckPossibility, Case5)
{
    int arr[] = {5, 7, 1, 8};
    ASSERT_EQUAL(true, checkPossibility(arr, 4));
}

#endif
