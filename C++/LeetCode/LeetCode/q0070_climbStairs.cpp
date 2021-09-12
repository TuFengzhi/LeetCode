// 70. Climbing Stairs
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps.In how many distinct ways can you
// climb to the top?

#include "pch.h"

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int buffer[2];
        buffer[0] = 1;
        buffer[1] = 2;
        for (int i = 3; i < n; i++)
        {
            buffer[(i + 1) % 2] = buffer[0] + buffer[1];
        }
        return buffer[0] + buffer[1];
    }
};
