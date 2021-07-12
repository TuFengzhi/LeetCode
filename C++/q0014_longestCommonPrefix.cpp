// 14. Longest Common Prefix
//
// Write a function to find the longest common prefix string amongst an array of
// strings.
//
// If there is no common prefix, return an empty string "".

#include "leetcode.h"

using namespace std;

class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int end_index = 0;
        int size = strs.size();
        int end_while = 1;

        if (size == 1)
        {
            return strs[0];
        }

        while (end_while)
        {
            for (int i = 1; i < size; i++)
            {
                if (strs[0][end_index] == '\0' || strs[i][end_index] == '\0' ||
                    strs[i][end_index] != strs[0][end_index])
                {
                    end_while = 0;
                    break;
                }
            }
            end_index++;
        }

        if (end_index > 0)
            return strs[0].substr(0, end_index - 1);
        else
            return "";
    }
};
