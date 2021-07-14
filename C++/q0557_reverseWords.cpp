// 557. Reverse Words in a String III
// Given a string s, reverse the order of characters in each word within a
// sentence while still preserving whitespace and initial word order.

#include "leetcode.h"

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
                s = reverseWord(s, start, end);
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

        s = reverseWord(s, start, end);

        return s;
    }

  private:
    string reverseWord(string s, int start, int end)
    {
        while (start < end)
        {
            s[start] = s[start] ^ s[end];
            s[end] = s[start] ^ s[end];
            s[start] = s[start] ^ s[end];

            start++;
            end--;
        }

        return s;
    }
};
