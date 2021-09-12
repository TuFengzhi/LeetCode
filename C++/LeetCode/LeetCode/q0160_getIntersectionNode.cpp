// 160. Intersection of Two Linked Lists
//
// Given the heads of two singly linked-lists headA and headB, return the node
// at which the two lists intersect. If the two linked lists have no
// intersection at all, return null.

#include "pch.h"

using namespace std;

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int len_a = 0, len_b = 0;
        ListNode *itr_a = headA, *itr_b = headB;

        while (itr_a)
        {
            len_a++;
            itr_a = itr_a->next;
        }
        while (itr_b)
        {
            len_b++;
            itr_b = itr_b->next;
        }

        itr_a = headA;
        itr_b = headB;

        if (len_a > len_b)
        {
            for (int i = 0; i < len_a - len_b; i++)
            {
                itr_a = itr_a->next;
            }
        }
        else if (len_a < len_b)
        {
            for (int i = 0; i < len_b - len_a; i++)
            {
                itr_b = itr_b->next;
            }
        }

        int len = min(len_a, len_b);
        ListNode *ret = NULL;
        for (int i = 0; i < len; i++)
        {
            if (itr_a == itr_b)
            {
                ret = itr_a;
                break;
            }
            else
            {
                itr_a = itr_a->next;
                itr_b = itr_b->next;
            }
        }

        return ret;
    }
};
