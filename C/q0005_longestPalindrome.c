// 5. Longest Palindromic Substring
// Given a string s, return the longest palindromic substring in s.

#include "ctest.h"
#include "leetcode.h"

char *longestPalindrome(char *s)
{
    size_t len = strlen(s);
    int max_len = 0;
    for (int i = len; i >= 1; i--)
    {
        for (int j = 0; j < len - i + 1; j++)
        {
            printf("\n");
            for (int k = 0; k < i; k++)
            {
                printf("%c", s[j + k]);
            }
            printf("\n");

            if (IsPalindrome(s + j, i))
            {
                char *ret = (char *)malloc(i + 1);
                strncpy(ret, s + j, i);
                ret[i] = '\0';
                return ret;
            }
        }
    }
    return NULL;
}

#if defined(Q0005)

CTEST(Q0001longestPalindrome, Case1)
{
    char in[] = "cbbd";
    char *out = longestPalindrome(in);
    printf("\n%s\n", out);
    printf("\n\n");
}

#endif
