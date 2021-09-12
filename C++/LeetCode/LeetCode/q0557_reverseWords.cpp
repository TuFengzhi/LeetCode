// 557. Reverse Words in a String III
// Given a string s, reverse the order of characters in each word within a
// sentence while still preserving whitespace and initial word order.

#include "pch.h"

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int len = s.size();
        int start = -1, end = -1, finish = 1;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == ' ')
            {
                while (start < end)
                {
                    swap(s[start], s[end]);

                    start++;
                    end--;
                }
                end = start;
                finish = 1;
            }
            else if (finish)
            {
                start = i;
                end = i;
                finish = 0;
            }
            else
            {
                end = i;
            }
        }

        while (start < end)
        {
            swap(s[start], s[end]);

            start++;
            end--;
        }

        return s;
    }
};
