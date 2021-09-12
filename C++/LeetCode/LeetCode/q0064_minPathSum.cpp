// 64. Minimum Path Sum
// Given a m x n grid filled with non-negative numbers, find a path from top
// left to bottom right, which minimizes the sum of all numbers along its path.
//
// Note : You can only move either down or right at any point in time.

#include "pch.h"

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ret(m, vector<int>(n, 0));
        ret[0][0] = grid[0][0];

        for (int i = 1; i < m; i++)
        {
            ret[i][0] = ret[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < n; i++)
        {
            ret[0][i] = ret[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                ret[i][j] = min(ret[i][j - 1], ret[i - 1][j]) + grid[i][j];
            }
        }

        return ret[m - 1][n - 1];
    }
};
