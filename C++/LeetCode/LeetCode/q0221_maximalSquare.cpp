// 221. Maximal Square
//
// Given an m x n binary matrix filled with 0's and 1's, find the largest square
// containing only 1's and return its area.
//
// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 300
// matrix[i][j] is '0' or '1'.

#include "pch.h"

using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = matrix[0][0] - '0';

        int max_size = dp[0][0];

        for (int i = 1; i < m; i++)
        {
            dp[i][0] = matrix[i][0] - '0';
            max_size = max(max_size, dp[i][0]);
        }
        for (int i = 1; i < n; i++)
        {
            dp[0][i] = matrix[0][i] - '0';
            max_size = max(max_size, dp[0][i]);
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] - '0')
                    dp[i][j] =
                        1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                else
                    dp[i][j] = 0;
                max_size = max(max_size, dp[i][j]);
            }
        }

        return max_size * max_size;
    }
};
