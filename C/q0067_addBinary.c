// 67. Add Binary
// Given two binary strings a and b, return their sum as a binary string.

#include "ctest.h"
#include "leetcode.h"

size_t Binary2Decimal(const char *ch)
{
    size_t ret = 0;
    size_t len = strlen(ch);
    for (int i = len - 1; i >= 0; i--)
    {
        ret += ch[i] == '1' ? 1 << (len - i - 1) : 0;
    }
    return ret;
}

char *Decimal2Binary(int decimal)
{
    int total_size = 0, cur = decimal;
    while (cur)
    {
        total_size++;
        cur /= 2;
    }
    char *ret = (char *)malloc(total_size + 1);

    ret[total_size] = '\0';

    for (int i = total_size - 1; i >= 0; i--)
    {
        ret[i] = decimal % 2 == 0 ? '0' : '1';
        decimal /= 2;
    }

    return ret;
}

char *addBinary(char *a, char *b)
{
    size_t ai = Binary2Decimal(a);
    size_t bi = Binary2Decimal(b);
    int ret = ai + bi;

    return Decimal2Binary(ret);
}

#if defined(Q0067) || 1

CTEST(Q0067addBinary, Case1)
{
    char *ret = addBinary("1", "11");
    printf("\nRet: %s\n", ret);
}

#endif
