#include <iostream>
#include <vector>
class Solution {
public:
    bool isPalindrome(int x) {
        if (0 > x)
        {
            return false;
        }
        
        if (0 < x && x < 10)
        {
            return true;
        }

        int max = 0x7fffffff, min = 0x80000000;
        long long nResult = 0;
        int tmp = x;
        while (x != 0)
        {
            auto i = x % 10;
            x = x / 10;
            nResult = nResult * 10 + i;
            if (nResult < min || nResult > max)
            {
                return false;
            }
        }

        return tmp == nResult;
    }
};

int main()
{
    int a1 = 2147483647, a2 = 21, a3 = 22, a4 = 12345, a5 = 12321, a6 = -212212;
    Solution s;
    auto b1 = s.isPalindrome(a1);
    auto b2 = s.isPalindrome(a2);
    auto b3 = s.isPalindrome(a3);
    auto b4 = s.isPalindrome(a4);
    auto b5 = s.isPalindrome(a5);
    auto b6 = s.isPalindrome(a6);

    printf("%d is %d\n", a1, b1);
    printf("%d is %d\n", a2, b2);
    printf("%d is %d\n", a3, b3);
    printf("%d is %d\n", a4, b4);
    printf("%d is %d\n", a5, b5);
    printf("%d is %d\n", a6, b6);

    return 1;
}
