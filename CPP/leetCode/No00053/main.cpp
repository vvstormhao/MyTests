#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int nSize = nums.size();
        if (0 == nSize)
        {
            return INT_MIN;
        }

        vector<int> dp(nSize);
        dp[0] = nums[0];
        int result = dp[0];
        for (int index = 1;index < nSize;++index)
        {
            dp[index] = max(dp[index - 1] + nums[index], nums[index]);
            result = max(result, dp[index]);
        }

        return result;
    }
};

int main()
{
    return 1;
}