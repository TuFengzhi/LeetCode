// 19. Remove Nth Node From End of List
// Given the head of a linked list, remove the nth node from the end of the list
// and return its head.

#include "ctest.h"
#include "leetcode.h"

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    int len = 0;
    struct ListNode *head_itr = head;
    while (head_itr)
    {
        head_itr = head_itr->next;
        len++;
    }

    n = len - n;
    head_itr = head;
    for (int i = 0; i < n - 1; i++)
    {
        head_itr = head_itr->next;
    }
    if (n == 0)
    {
        head = head->next;
    }
    else
    {
        head_itr->next = head_itr->next->next;
    }

    return head;
}

#if defined(Q0019)

CTEST(Q0019removeNthFromEnd, Case1)
{
#define l1_len 5
    int val1[l1_len] = {1, 2, 3, 4, 5};
    struct ListNode ln1[l1_len];
    struct ListNode l1;
    int i = 0;
    for (struct ListNode *itr = &l1; i < l1_len; i++)
    {
        itr->next = &ln1[i];
        itr->next->val = val1[i];
        itr = itr->next;
        itr->next = NULL;
    }

    struct ListNode *ret = removeNthFromEnd(l1.next, 5);

#undef l1_len
}

#endif
