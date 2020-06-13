#include<iostream>

class Solution {
public:
    int mySqrt(int x) {
        return Search(0, x, x);
    }
private:
    int Search(int nLeft, int nRight, int nTarget)
    {
        printf("left is %d, right is %d\n", nLeft, nRight);
        if (nLeft >= nRight)
        {
            return nRight;
        }
        int nMid = nLeft + (nRight - nLeft) / 2;
        int nResult = nMid * nMid;
        if (nMid * nMid == nTarget)
        {
            return nMid;
        }

        if (nResult > nTarget)
        {
            return Search(nLeft, nMid - 1, nTarget);
        }
        else 
        {
            return Search(nMid + 1, nRight, nTarget);
        }
    }
};

int main()
{
    Solution s;
    auto ret = s.mySqrt(9);
    printf("ret is %d\n", ret);
}