/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) 
{
    int * Nums = malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i ++)
    {
        for (int j = i + 1; j < numsSize; j ++)
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