#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (nullptr == p && nullptr == q)
        {
            return true;
        }
        else if ((nullptr == p && nullptr != q) || (nullptr != p && nullptr == q))
        {
            return false;
        }
        else
        {
            bool b = isSameTree(p->left, q->left);
            if (!b)
            {
                return b;
            }
            b = isSameTree(p->right, q->right);
            if (!b)
            {
                return b;
            }  

            if (p->val == q->val)
            {
                return true;
            }
            else
            {
                return false;
            }     
        }
    }
};