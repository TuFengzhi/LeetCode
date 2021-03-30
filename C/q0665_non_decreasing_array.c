#include "ctest.h"
#include "leetcode.h"

bool checkPossibility(int *nums, int numsSize)
{
    if (numsSize == 0 || numsSize == 1)
    {
        return true;
    }

    bool result = true;
    bool one_time = true;

    if (nums[0] > nums[1])
    {
        nums[0] = nums[1];
        one_time = false;
    }

    for (int i = 1; i < numsSize - 1; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            if (!one_time)
            {
                return false;
            }
            else
            {
                if (nums[i + 1] < nums[i - 1])
                {
                    return false;
                }
                one_time = false;
            }
        }
    }

    return result;
}

#if defined(Q0665) || 1

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

#endif
