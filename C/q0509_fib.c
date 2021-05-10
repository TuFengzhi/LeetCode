// 509. Fibonacci Number
// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the
// Fibonacci sequence, such that each number is the sum of the two preceding
// ones, starting from 0 and 1. That is, F(0) = 0, F(1) = 1 F(n) = F(n - 1) +
// F(n - 2), for n > 1. Given n, calculate F(n).

#include "ctest.h"
#include "leetcode.h"

int fib(int n)
{
    static int fib_array[] = {
        0,     1,     1,      2,      3,      5,      8,     13,
        21,    34,    55,     89,     144,    233,    377,   610,
        987,   1597,  2584,   4181,   6765,   10946,  17711, 28657,
        46368, 75025, 121393, 196418, 317811, 514229, 832040};

    return fib_array[n];
}

#if defined(Q0509)

CTEST(Q0509fib, Case1) {}

#endif
