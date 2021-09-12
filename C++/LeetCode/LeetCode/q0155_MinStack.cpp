// 155. Min Stack
//
// Design a stack that supports push, pop, top, and retrieving the minimum
// element in constant time.
//
// Implement the MinStack class :
// MinStack() initializes the stack object.
// void push(val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.

#include "pch.h"

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

class MinStack
{
public:
    /** initialize your data structure here-> */
    MinStack()
    {
        this->head = new Node(0);
        this->total_size = 0;
        this->min_val = 0;
    }

    void push(int val)
    {
        Node *node = new Node(val);
        node->next = this->head->next;
        this->head->next = node;
        if (this->total_size == 0)
        {
            this->min_val = val;
        }
        else
        {
            this->min_val = min(this->min_val, val);
        }
        this->total_size++;
    }

    void pop()
    {
        Node *node = head->next;
        this->head->next = this->head->next->next;

        delete node;

        this->total_size--;

        if (this->total_size)
        {
            node = head->next;
            this->min_val = node->val;

            for (int i = 0; i < this->total_size - 1; i++)
            {
                node = node->next;
                this->min_val = min(this->min_val, node->val);
            }
        }
    }

    int top() { return this->head->next->val; }

    int getMin() { return this->min_val; }

private:
    Node *head;

    int min_val;

    int total_size;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// TEST(MinStack, Case1)
// {
//     MinStack minStack = new MinStack();
//     minStack->push(-2);
//     minStack->push(0);
//     minStack->push(-3);
//     minStack->getMin(); // return -3
//     minStack->pop();
//     minStack->top();    // return 0
//     minStack->getMin(); // return -2
// }
