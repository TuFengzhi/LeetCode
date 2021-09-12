// 141. Linked List Cycle

// Given head, the head of a linked list, determine if the linked list has a
// cycle in it.
//
// There is a cycle in a linked list if there is some node in the list that can
// be reached again by continuously following the next pointer. Internally,
// pos is used to denote the index of the node that tail's next pointer is
// connected to. Note that pos is not passed as a parameter.
//
// Return true if there is a cycle in the linked list. Otherwise, return false.

#include "pch.h"

using namespace std;

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        bool ret = false;
        if (head == NULL || head->next == NULL)
        {
            return false;
        }
        ListNode *fast = head->next;
        ListNode *slow = head;

        if (fast == slow)
        {
            ret = true;
        }
        else
        {
            while (fast != slow)
            {
                if (fast && slow)
                {
                    if (fast->next)
                        fast = fast->next->next;
                    else
                        break;
                    slow = slow->next;
                    if (fast == slow && fast && slow)
                    {
                        ret = true;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }

        return ret;
    }
};
