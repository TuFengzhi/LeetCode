// 67. Add Binary
// Given two binary strings a and b, return their sum as a binary string.

#include "ctest.h"
#include "leetcode.h"

char *addBinary(char *a, char *b)
{
    size_t al = strlen(a);
    size_t bl = strlen(b);
    char *long_str = NULL, *short_str = NULL;
    int long_len = 0, short_len = 0;
    int carry = 0;

    if (al > bl)
    {
        long_str = a;
        short_str = b;
        long_len = al;
        short_len = bl;
    }
    else
    {
        long_str = b;
        short_str = a;
        long_len = bl;
        short_len = al;
    }
    int i = 0;
    for (; i < short_len; i++)
    {
        if ((short_str[short_len - i - 1] == '1') && (carry == 1))
        {
            carry = 1;
        }
        else if ((short_str[short_len - i - 1] == '1') || (carry == 1))
        {
            // printf("%c", long_str[long_len - i - 1]);
            if (long_str[long_len - i - 1] == '1')
            {
                long_str[long_len - i - 1] = '0';
                carry = 1;
            }
            else
            {
                long_str[long_len - i - 1] = '1';
                carry = 0;
            }
        }
    }
    while (carry)
    {
        if (i == long_len)
        {
            break;
        }
        if (long_str[long_len - i - 1] == '1')
        {
            long_str[long_len - i - 1] = '0';
            carry = 1;
        }
        else
        {
            long_str[long_len - i - 1] = '1';
            carry = 0;
        }
        i++;
    }
    if (carry)
    {
        // Add One More Bit
        // printf("Carry On\n");
        char *ret = (char *)malloc(long_len + 2);
        ret[0] = '1';
        strncpy(ret + 1, long_str, long_len);
        ret[long_len + 1] = '\0';
        long_str = ret;
    }
    else
    {
        char *ret = (char *)malloc(long_len + 1);
        strncpy(ret, long_str, long_len);
        ret[long_len] = '\0';
        long_str = ret;
    }

    return long_str;
}

#if defined(Q0067)

CTEST(Q0067addBinary, Case1)
{
    char a[] = "1010";
    char b[] = "1011";
    char *ret = addBinary(a, b);
    char *ref = "10101";
    printf("\nRet: %s\n", ret);
    printf("Ref: %s\n", ref);
}

#endif
