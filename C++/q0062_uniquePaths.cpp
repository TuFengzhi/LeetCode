// 62. Unique Paths
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in
// the diagram below).
//
// The robot can only move either down or right at any point in time.The robot
// is trying to reach the bottom-right corner of the grid(marked 'Finish' in the
// diagram below).
//
// How many possible unique paths are there?

#include "leetcode.h"

using namespace std;

class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        int ret[m][n];

        for (int i = 0; i < m; i++)
        {
            ret[i][0] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            ret[0][i] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                ret[i][j] = ret[i - 1][j] + ret[i][j - 1];
            }
        }

        return ret[m - 1][n - 1];
    }
};
