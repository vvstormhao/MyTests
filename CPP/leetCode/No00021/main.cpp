 #include <iostream>
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (nullptr == l1 && nullptr != l2)
        {   
            printf("return %d\n", l2->val);
            return l2;
        }
        else if (nullptr != l1 && nullptr == l2)
        {
            printf("return %d\n", l1->val);
            return l1;
        }
        else
        {
            printf("return nullptr\n");
            return nullptr;
        }
        

        ListNode *ret = l1->val < l2->val ? l1 : l2;
        if (l1->val < l2->val)
        {
            ret->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            ret->next = mergeTwoLists(l1, l2->next);
        }
        return ret;
    }
};

int main()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(6);
    ListNode *node7 = new ListNode(7);

    node1->next = node3;
    node3->next = node5;
    node5->next = node7;

    node2->next = node4;
    node4->next = node6;

    Solution s;
    ListNode *ret = s.mergeTwoLists(node1, node2);

    while(nullptr != ret->next)
    {
        printf("%d\n", ret->val);
        ret = ret->next;
    }

    return 1;

}