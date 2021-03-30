#include "ctest.h"
#include "leetcode.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
char ***partition(char *s, int *returnSize, int **returnColumnSizes)
{
    int s_s = strlen(s);

    char ***ret = malloc(sizeof(char ***));

    if (s_s == 1)
    {
        *returnSize = 1;
        *returnColumnSizes = malloc(sizeof(int));
        **ret = malloc(sizeof(char **));
        *ret = malloc(sizeof(char *));
        ret[0][0] = s[0];
        returnColumnSizes[0] = 1;
    }

    return ret;
}

#if defined(Q0131)

CTEST(Q0131PalindromePartitioning, Case1) {}

#endif
