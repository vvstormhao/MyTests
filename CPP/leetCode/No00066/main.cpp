#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int nSize = int(digits.size());
        if (9 != digits[nSize - 1])
        {
            digits[nSize - 1] += 1;
            return digits;
        }

        for(int i=digits.size()-1;i>=0;i--)
        {
            ++digits[i];

            if(digits[i]!=10) 
                return digits;
            else
                digits[i]=0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    vector<int> vec = {9,8,7,6,5,4,3,2,1,0};
    Solution s;
    auto ret = s.plusOne(vec);

    auto iterStart = ret.cbegin();
    auto iterEnd = ret.cend();
    for (; iterStart != iterEnd; ++iterStart)
    {
        printf("%d,", *iterStart);
    }
    printf("\n");
    return 1;
}