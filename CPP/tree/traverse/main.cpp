#include <iostream>

typedef struct TreeNode
{
    int nValue;
    TreeNode *pLeft;
    TreeNode *pRight;
}TreeNode;

void FirstTraverse(TreeNode *pRoot)
{
    if (nullptr == pRoot)
    {
        return;
    }

    FirstTraverse(pRoot->pLeft);
    printf("%d ", pRoot->nValue);
    FirstTraverse(pRoot->pRight);
}

void MidTraverse(TreeNode *pRoot)
{
    if (nullptr == pRoot)
    {
        return;
    }

    printf("%d ", pRoot->nValue);
    MidTraverse(pRoot->pLeft);
    MidTraverse(pRoot->pRight);
}

void LastTraverse(TreeNode *pRoot)
{
    if (nullptr == pRoot)
    {
        return;
    }
    LastTraverse(pRoot->pLeft);
    LastTraverse(pRoot->pRight);
    printf("%d ", pRoot->nValue);

}

int main()
{
    TreeNode *pNode1 = new TreeNode();
    pNode1->nValue = 1;

    TreeNode *pNode2 = new TreeNode();
    pNode2->nValue = 2;   


    TreeNode *pNode3 = new TreeNode();
    pNode3->nValue = 3; 

    TreeNode *pNode4 = new TreeNode();
    pNode4->nValue = 4; 

    TreeNode *pNode5 = new TreeNode();
    pNode5->nValue = 5; 

    TreeNode *pNode6 = new TreeNode();
    pNode6->nValue = 6; 

    TreeNode *pNode7 = new TreeNode();
    pNode7->nValue = 7; 

    TreeNode *pNode8 = new TreeNode();
    pNode8->nValue = 8; 

    pNode2->pLeft = pNode1;
    pNode2->pRight = nullptr;

    pNode3->pLeft = pNode2;
    pNode3->pRight = pNode4; 

    pNode4->pLeft = nullptr;
    pNode4->pRight = nullptr;  

    pNode5->pLeft = pNode3;
    pNode5->pRight = pNode7;

    pNode6->pLeft = nullptr;
    pNode6->pRight = nullptr;  

    pNode7->pLeft = pNode6;
    pNode7->pRight = pNode8;    

    pNode8->pLeft = nullptr;
    pNode8->pRight = nullptr;  

    FirstTraverse(pNode5);
    printf("\n");
    MidTraverse(pNode5);
    printf("\n");
    LastTraverse(pNode5);
    printf("\n");
}