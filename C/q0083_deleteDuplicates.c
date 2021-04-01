// 83. Remove Duplicates from Sorted List
// Given the head of a sorted linked list, delete all duplicates such that each
// element appears only once. Return the linked list sorted as well.

#include "ctest.h"
#include "leetcode.h"

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    if (!head)
    {
        return head;
    }

    struct ListNode *head_itr = head;

    while (head_itr->next)
    {
        if (head_itr->val == head_itr->next->val)
        {
            // Remove duplicates
            head_itr->next = head_itr->next->next;
        }
        else
        {
            // Move to next node
            head_itr = head_itr->next;
        }
    }

    return head;
}

#if defined(Q0083)

CTEST(Q0083deleteDuplicates, Case1)
{
#define l1_len 5
    int val1[l1_len] = {1, 3, 3, 4, 7};
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

    struct ListNode *ret = deleteDuplicates(l1.next);

#undef l1_len
}

#endif
