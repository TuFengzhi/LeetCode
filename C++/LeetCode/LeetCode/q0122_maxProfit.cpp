// 122. Best Time to Buy and Sell Stock II
// You are given an array prices where prices[i] is the price of a given stock
// on the ith day.
//
// Find the maximum profit you can achieve. You may complete as many
// transactions as you like (i.e., buy one and sell one share of the stock
// multiple times).
//
// Note : You may not engage in multiple transactions simultaneously(i.e., you
// must sell the stock before you buy again).

#include "pch.h"

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int size = prices.size();
        vector<int> buy(size), sell(size);
        buy[0] = -prices[0];
        sell[0] = 0;
        for (int i = 1; i < size; i++)
        {
            buy[i] = max(sell[i - 1] - prices[i], buy[i - 1]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }

        return sell[size - 1];
    }
};
