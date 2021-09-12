//
// pch.h
//

#pragma once

#include "gtest/gtest.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right)
    {
    }
};