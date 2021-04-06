// 19. Remove Nth Node From End of List
// Given the head of a linked list, remove the nth node from the end of the list
// and return its head.

#include "ctest.h"
#include "leetcode.h"

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode dummyHead;
    dummyHead.next = head;
    struct ListNode *slow = &dummyHead;
    struct ListNode *fast = &dummyHead;

    for (int i = 0; i < n + 1; i++)
    {
        fast = fast->next;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;

    return dummyHead.next;
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

    printf("\n");
    while (ret != NULL)
    {
        printf("%d ", ret->val);
        ret = ret->next;
    }
    printf("\n");

#undef l1_len
}

#endif
