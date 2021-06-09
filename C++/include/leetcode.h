#ifndef CPP_LEETCODE_H
#define CPP_LEETCODE_H

#include "build/googletest-src/googletest/include/gtest/gtest.h"

#include <iostream>
#include <stack>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

#endif
