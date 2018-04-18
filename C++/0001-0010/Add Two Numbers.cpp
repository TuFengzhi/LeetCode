/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // 算法思路，两两相加，尾部插入
    ListNode *ret_head= 0, *ret_tail = 0;
    int inc = 0;
    
    while(l1 || l2 || inc)
    {
        cout << l1 << endl;
        cout << l2 << endl;
        int val = inc;
        if(l1)
        {
            val += l1->val;
            l1 = l1->next;
        }
        if(l2)
        {
            val += l2->val;
            l2 = l2->next;
        }
        
        inc = 0;
        // 计算值
        if(val >= 10)
        {
            inc = 1;
            val -= 10;
        }
        
        ListNode *t = new ListNode(val);
        if(ret_head == 0)
        {
            ret_head = t;
            ret_tail = t;
        }
        else
        {
            ret_tail->next = t;
            ret_tail = t;
        }
        
        cout << l1 << endl;
        cout << l2 << endl;
    }
    
    return ret_head;
}
};