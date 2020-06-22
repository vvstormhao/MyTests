#include <iostream>
#include <vector>

using namespace std;
class NumArray {
public:
    NumArray(vector<int>& nums) 
    {
        int n = nums.size();
        if (0 == n)
        {
            return;
        }

        pDP = new int[n];
        pDP[0] = nums[0];
        printf("pDP[0] = %d\n", nums[0]);

        for (int i = 1; i < n; ++i)
        {
            pDP[i] = pDP[i - 1] + nums[i];
            printf("pDP[%d] = %d\n", i, pDP[i]);
        }

    }
    
    int sumRange(int i, int j) {
        if (0 == i) return pDP[j];
        else return pDP[j] - pDP[i - 1];
    }
private:
    int *pDP;
};