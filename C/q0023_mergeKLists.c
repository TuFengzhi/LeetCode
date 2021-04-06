// 23. Merge k Sorted Lists
// You are given an array of k linked-lists lists, each linked-list is
// sorted in ascending order. Merge all the linked-lists into one sorted
// linked-list and return it.

#include "ctest.h"
#include "leetcode.h"

struct ListNode *MergeTwoLists(struct ListNode *l1, struct ListNode *l2)
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

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
    if (listsSize == 0)
    {
        return NULL;
    }
    if (listsSize == 1)
    {
        return *lists;
    }

    struct ListNode *left = mergeKLists(lists, listsSize / 2);
    struct ListNode *right =
        mergeKLists(lists + listsSize / 2, listsSize - listsSize / 2);
    struct ListNode *ret = MergeTwoLists(left, right);

    return ret;
}

#if defined(Q0023)

CTEST(Q0023mergeKLists, Case1) {}

#endif
