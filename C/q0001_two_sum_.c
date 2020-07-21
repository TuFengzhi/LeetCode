#include "leetcode.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target)
{
    int *Nums = malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                Nums[0] = i;
                Nums[1] = j;

                return Nums;
            }
        }
    }

    return Nums;
}

void q0001TwoSumTest(void)
{
    int32_t numsSize = 4;
    int32_t nums[] = {1, 2, 5, 7};
    int32_t target = 9;

    int32_t *result = twoSum(nums, numsSize, target);
    printf("Result: %d %d\n", result[0], result[1]);
    free(result);
}
