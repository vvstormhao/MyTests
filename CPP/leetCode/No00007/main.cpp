#include <vector>
#include <iostream>

class Solution
{
public:
    int Reverse(int num)
    {
        int max = 0x7fffffff, min = 0x80000000;

        long long nResult = 0;
        while (num != 0)
        {
            auto i = num % 10;
            num = num / 10;
            nResult = nResult * 10 + i;
            if (nResult>max||nResult<min)
            {
                return 0;
            }
            printf("i is %d, nResult is %d\n", i, nResult);
        }

        return nResult;
    }

};

int main()
{
    Solution s;
    auto ret = s.Reverse(-1534236469);
    printf("%d\n", ret);

    return 1;
}