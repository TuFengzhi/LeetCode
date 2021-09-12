// 121. Best Time to Buy and Sell Stock
// You are given an array prices where prices[i] is the price of a given stock
// on the ith day.
//
// You want to maximize your profit by choosing a single day to buy one stock
// and choosing a different day in the future to sell that stock.
//
// Return the maximum profit you can achieve from this transaction.If you cannot
// achieve any profit, return 0.

#include "pch.h"

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy_price = prices[0];
        int max_profit = 0;
        int size = prices.size();

        for (int i = 1; i < size; i++)
        {
            max_profit = max(max_profit, prices[i] - buy_price);
            buy_price = min(buy_price, prices[i]);
        }

        return max_profit;
    }
};
