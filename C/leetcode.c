#include "leetcode.h"

int IsPalindrome(char *s, size_t len)
{
    int half_s_s = len / 2;
    for (int i = 0; i < half_s_s; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            return 0;
        }
    }
    return 1;
}
