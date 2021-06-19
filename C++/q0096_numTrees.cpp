// 96. Unique Binary Search Trees
// Given an integer n, return the number of structurally unique BST's (binary
// search trees) which has exactly n nodes of unique values from 1 to n.

#include "leetcode.h"

using namespace std;

class Solution
{
  public:
    int numTrees(int n)
    {
        int ret[n + 1];
        memset(ret, 0, sizeof(ret));

        ret[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                ret[i] += ret[j] * ret[i - j - 1];
            }
        }

        return ret[n];
    }
};
