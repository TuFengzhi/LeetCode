// 139. Word Break
// Given a string s and a dictionary of strings wordDict, return true if s can
// be segmented into a space-separated sequence of one or more dictionary words.
//
// Note that the same word in the dictionary may be reused multiple times in the
// segmentation.

#include "pch.h"

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int size = s.length();
        vector<bool> ret(size + 1);
        ret[0] = true;
        for (int i = 1; i <= size; i++)
        {
            ret[i] = false;
            for (int j = i - 1; j >= 0; j--)
            {
                if (ret[j] && find(wordDict.begin(), wordDict.end(),
                                   s.substr(j, i - j)) != wordDict.end())
                {
                    ret[i] = true;
                    break;
                }
            }
        }

        return ret[size];
    }
};
