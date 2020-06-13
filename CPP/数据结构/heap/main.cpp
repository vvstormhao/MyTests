#include <iostream>

void makeheap(int nums[]) 
{
    
}

// 最后一颗子树根节点位置 k/2 （k为节点总数）
// 左儿子 i + 1 (i为根节点)
// 右儿子 i + 2 (i为根节点)
// 父亲节点 i/2
void swim(int nums[], int pos)
{
    int tmp = nums[2 * pos];
    nums[2 * pos] = nums[pos];
    nums[pos] = tmp;
}

void slink(int nums[], int pos)
{
    int nChild = pos + 1;
    if (nums[pos + 1] < nums[pos + 2])
    {
        nChild = pos + 2;
    }

    int tmp = nums[pos];
    nums[pos] = nums[nChild];
    nums[nChild] = tmp;
    slink(nums, nChild);
}


int main()
{

}