// 206. Reverse Linked List
//
// Given the head of a singly linked list, reverse the list, and return the
// reversed list.

#include "pch.h"

using namespace std;

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
