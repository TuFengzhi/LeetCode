#ifndef LEETCODE_H
#define LEETCODE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    struct ListNode *next;
};

int IsPalindrome(char *s, size_t len);

#endif
