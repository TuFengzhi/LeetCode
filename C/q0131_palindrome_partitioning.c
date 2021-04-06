#include "ctest.h"
#include "leetcode.h"

int IsPalindrome(char *s)
{
    int s_s = strlen(s);
    int half_s_s = s_s / 2;
    for (int i = 0; i < half_s_s; i++)
    {
        if (s[i] != s[s_s - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

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
        ret[0] = malloc(sizeof(char **));
        ret[0][0] = malloc(sizeof(char *) + 1);
        ret[0][0][0] = s[0];
        ret[0][0][1] = s[1];
        *returnColumnSizes[0] = 1;
    }
    else
    {
        char current_char = s[s_s - 1];
        s[s_s - 1] = '\0';
        int returnSize = 0;
        int *returnColumnSizes = NULL;
        char ***last_ret = partition(s, &returnSize, &returnColumnSizes);
        for (int i = 0; i < returnSize; i++)
        {
            int last_last_size = strlen(last_ret[i][returnSize - 1]);
            char current[last_last_size + 1 + 1];
            strcpy(current, last_ret[i][returnSize - 1]);
            current[last_last_size] = current_char;
            current[last_last_size + 1] = '\0';
            int is_p = IsPalindrome(current);
            printf("TEST\n");
        }
        printf("TEST\n");
    }

    return ret;
}

#if defined(Q0131)

CTEST(Q0131PalindromePartitioning, Case1)
{
    char s[] = "aa";
    int returnSize = 0;
    int *returnColumnSizes = NULL;
    char ***ret = partition(s, &returnSize, &returnColumnSizes);
    printf("END\n");
}

#endif
