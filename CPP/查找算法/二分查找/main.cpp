#include <iostream>


int Search(int nums[], int nLeft, int nRight, int nTarget)
{
    if (nLeft > nRight)
    {
        return nRight + 1;
    }

    int nMid = nLeft + (nRight - nLeft) / 2;
    printf("mid is %d, value %d  ", nMid, nums[nMid]);
    if (nums[nMid] == nTarget)
    {
        return nMid;
    }
    else if (nums[nMid] > nTarget)
    {
        printf("search range [%d, %d]\n", nLeft, nMid - 1);
        return Search(nums, nLeft, nMid - 1, nTarget);
    }
    else
    {
        printf("search range [%d, %d]\n", nMid + 1, nRight);
        return Search(nums, nMid + 1, nRight, nTarget);
    }
}
int main()
{
    int nums[10] = {1,3,5,7,9,10,15,17,20,25};
    int result = Search(nums, 0, 9, 28);
    printf("result is %d\n", result);
    return 1;
}