// 309. Best Time to Buy and Sell Stock with Cooldown
// You are given an array prices where prices[i] is the price of a given stock
// on the ith day.
//
// Find the maximum profit you can achieve.You may complete as many transactions
// as you like (i.e., buy one and sell one share of the stock multiple times)
// with the following restrictions:
// * After you sell your stock, you cannot buy stock on the next day(i.e.,
// cooldown one day).
//
// Note: You may not engage in multiple transactions simultaneously (i.e., you
// must sell the stock before you buy again).

#include "leetcode.h"

using namespace std;

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int size = prices.size();
        int dp[size][3]; // 0: Own Stock, 1: Cool Down, 2: Not Own Stock && Not
                         // Cool Down
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        for (int i = 1; i < size; i++)
        {
            dp[i][0] = max(dp[i - 1][2] - prices[i], dp[i - 1][0]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }

        return max(dp[size - 1][1], dp[size - 1][2]);
    }
};
