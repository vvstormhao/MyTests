#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto nSize = nums.size();
        if (0 == nSize) return 0;

        auto i = 0,j = 0;
        while (j < nSize)
        {
            if (nums[j] == val)
            {
                j++;
            }
            else
            {
                nums[i++] = nums[j++];
            }

        }

        return i;
    }
};


int main()
{
    vector<int> vec={3,2,2,3,3,3,2,2,3,3};
    Solution s;
    int ret = s.removeElement(vec, 3);
    printf("ret size is %d\n", ret);

    for (auto i = 0; i < ret; ++i)
    {
        printf("%d ", vec[i]);
    }

    printf("\n");
}

