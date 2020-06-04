#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto nSize = nums.size();
        auto j = 1;
        for (auto i = 0; i < nSize; ++i,++j)
        {
            while (j < nSize)
            {
                if ( nums[i] == nums[j])
                {
                    ++j;
                }
                else
                {
                    nums[i + 1] = nums[j];
                    break;
                }
            }

            if (j > nSize)
            {
                return i;
            }
        }

        return nSize;
    }
};

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        auto nSize = nums.size();
        if (0 == nSize)
        {
            return 0;
        }

        auto j = 0,i = 0;
        while (j < nSize)
        {
            if (nums[i] != nums[j])
            {
                ++i;
                nums[i] = nums[j];
            }
            ++j;
        }
        return i + 1;
    }
};

int main()
{
    vector<int> vec={1,2,3,3,3,4,5,6,6,6,7,9,9,10,10};
    Solution2 s;
    int ret = s.removeDuplicates(vec);
    printf("ret size is %d\n", ret);

    for (auto i = 0; i < ret; ++i)
    {
        printf("%d ", vec[i]);
    }

    printf("\n");
}