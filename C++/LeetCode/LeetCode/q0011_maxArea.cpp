// 11. Container With Most Water
// Given n non-negative integers a1, a2, ..., an , where each represents a point
// at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
// of the line i is at (i, ai) and (i, 0). Find two lines, which, together with
// the x-axis forms a container, such that the container contains the most
// water.

#include "pch.h"

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int size = height.size();
        int left = 0;
        int right = size - 1;
        int max_ret = min(height[left], height[right]) * (right - left);

        while (left < right)
        {
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
            int curr = min(height[left], height[right]) * (right - left);
            max_ret = max(max_ret, curr);
        }

        return max_ret;
    }
};
