// 21. Merge Two Sorted Lists

#include "ctest.h"
#include "leetcode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }

    struct ListNode *ret;
    struct ListNode *ret_itr;
    struct ListNode *del_itr;
    if (l1->val <= l2->val)
    {
        ret = l1;
        ret_itr = ret;
        l1 = l1->next;
        del_itr = l2;
    }
    else
    {
        ret = l2;
        ret_itr = ret;
        l2 = l2->next;
        del_itr = l1;
    }
    while (del_itr != NULL)
    {
        if (ret_itr->next == NULL)
        {
            ret_itr->next = del_itr;
            break;
        }
        if (del_itr->val <= ret_itr->next->val)
        {
            // Insert del_itr to ret_itr
            struct ListNode *tmp = del_itr->next;
            del_itr->next = ret_itr->next;
            ret_itr->next = del_itr;
            del_itr = tmp;
        }
        else
        {
            ret_itr = ret_itr->next;
        }
    }

    return ret;
}

#if defined(Q0021)

CTEST(Q0021MergeTwoSortedLists, Case1)
{
#define l1_len 4
#define l2_len 4
    int val1[l1_len] = {1, 3, 4, 7};
    int val2[l2_len] = {2, 4, 6, 8};
    struct ListNode ln1[l1_len];
    struct ListNode ln2[l2_len];
    struct ListNode l1;
    struct ListNode l2;
    int i = 0;
    for (struct ListNode *itr = &l1; i < l1_len; i++)
    {
        itr->next = &ln1[i];
        itr->next->val = val1[i];
        itr = itr->next;
        itr->next = NULL;
    }

    i = 0;
    for (struct ListNode *itr = &l2; i < l2_len; i++)
    {
        itr->next = &ln2[i];
        itr->next->val = val2[i];
        itr = itr->next;
        itr->next = NULL;
    }

    struct ListNode *ret = mergeTwoLists(l1.next, l2.next);

#undef l1_len
#undef l2_len
}

#endif
