#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int nTarget = m + n - 1;
        for (; i >= 0 && j>= 0;)
        {
            nums1[i] > nums2[j] ? nums1[nTarget--] = nums1[i--]:nums1[nTarget--] = nums2[j--];
        }

        if (i < 0)
        {
            for (int index = 0; index <= j; index++)
            {
                nums1[index] = nums2[index];
            }
        }          
    }

    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> &numsRange = m > n ? nums1:nums2;
        int i = m - 1, j = n - 1;
        int nTarget = m + n - 1;
        for (; i >= 0 && j>= 0;)
        {
            nums1[i] > nums2[j] ? nums1[nTarget--] = nums1[i--]:nums1[nTarget--] = nums2[j--];
        }

        if (i < 0)
        {
            for (int index = 0; index <= j; index++)
            {
                nums1[index] = nums2[index];
            }
        }          
    }

};

int main()
{
    vector<int> nums1 = {2,0};
    vector<int> nums2 = {0};

    Solution s;
    s.merge(nums1, 1, nums2, 0);

    for (int i = 0; i < 1; i++)
    {
        printf("%d ", nums1[i]);
    }
    printf("\n");
    return 1;
}