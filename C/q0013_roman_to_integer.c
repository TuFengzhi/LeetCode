#include "ctest.h"
#include "leetcode.h"

struct entry
{
    char *str;
    int n;
};

struct entry roma_one[] = {
    {"M", 1000},
    {"D", 500},
    {"C", 100},
    {"L", 50},
    {"X", 10},
    {"V", 5},
    {"I", 1}};

struct entry roma_two[] = {
    {"CM", 900},
    {"CD", 400},
    {"XC", 90},
    {"XL", 40},
    {"IX", 9},
    {"IV", 4}};

int findKey(char *s, int length)
{
    if (length == 1)
    {
        for (int i = 0; i < 7; i++)
        {
            if (roma_one[i].str[0] == s[0])
            {
                return roma_one[i].n;
            }
        }
    }
    else if (length == 2)
    {
        for (int i = 0; i < 6; i++)
        {
            if (roma_two[i].str[0] == s[0] && roma_two[i].str[1] == s[1])
            {
                return roma_two[i].n;
            }
        }
    }
    return 0;
}

int romanToInt(char *s)
{
    int size = strlen(s);
    int value_sum = 0;
    int index = 0;
    while (size)
    {
        int value = 0;
        if (size >= 2)
        {
            value = findKey(s + index, 2);
            if (value != 0)
            {
                value_sum += value;
                index += 2;
                size -= 2;
            }
            else
            {
                value_sum += findKey(s + index, 1);
                index++;
                size--;
            }
        }
        else
        {
            value_sum += findKey(s + index, 1);
            index++;
            size--;
        }
    }

    return value_sum;
}

#if defined(Q0013) || 1

CTEST(Q0013RomanToInt, Case1)
{
    ASSERT_EQUAL(3, romanToInt("III"));
}

CTEST(Q0013RomanToInt, Case2)
{
    ASSERT_EQUAL(4, romanToInt("IV"));
}

CTEST(Q0013RomanToInt, Case3)
{
    ASSERT_EQUAL(9, romanToInt("IX"));
}

CTEST(Q0013RomanToInt, Case4)
{
    ASSERT_EQUAL(58, romanToInt("LVIII"));
}

CTEST(Q0013RomanToInt, Case5)
{
    ASSERT_EQUAL(1994, romanToInt("MCMXCIV"));
}

#endif
