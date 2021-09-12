// 279. Perfect Squares
// Given an integer n, return the least number of perfect square numbers that
// sum to n.
//
// A perfect square is an integer that is the square of an integer; in other
// words, it is the product of some integer with itself. For example, 1, 4, 9,
// and 16 are perfect squares while 3 and 11 are not.

#include "pch.h"

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            int sqrt_i = sqrt(i);
            int min_num = INT_MAX;
            for (int j = 1; j <= sqrt_i; j++)
            {
                min_num = min(min_num, 1 + dp[i - j * j]);
            }
            dp[i] = min_num;
        }

        return dp[n];
    }
};
