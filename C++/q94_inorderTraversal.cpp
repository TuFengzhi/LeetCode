// Binary Tree Inorder Traversal

#include "leetcode.h"

using namespace std;

class Solution
{
  public:
    vector<int> inorderTraversal1(TreeNode *root)
    {
        vector<int> ret;
        if (root == NULL)
            return ret;

        ret = inorderTraversal1(root->left);
        ret.push_back(root->val);
        vector<int> right = inorderTraversal1(root->right);
        ret.insert(ret.end(), right.begin(), right.end());

        return ret;
    }

    vector<int> inorderTraversal2(TreeNode *root)
    {
        vector<int> ret;
        if (root == NULL)
            return ret;

        TreeNode *cur = root;
        stack<TreeNode *> st;
        while ((!st.empty()) || cur != NULL)
        {
            while (cur != NULL)
            {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            ret.push_back(cur->val);
            cur = cur->right;
        }

        return ret;
    }
};
