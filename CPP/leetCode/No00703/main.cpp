#include <iostream>
#include <vector>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        
    }
    
    int add(int val) {

    }
private:
    void sink(vector<int>& nums, int nPos, int nSize)
    {
        if (2 * nPos + 2  < nSize && nums[nPos] > min(nums[2 * nPos + 1], nums[2 * nPos + 2]))
        {
            if (nums[2 * nPos + 1] < nums[2 * nPos + 2] )
            {
                swap(nums[nPos], nums[2 * nPos + 1]);
                sink(nums, 2 * nPos + 1, nSize);
            }
            else
            {
                swap(nums[nPos], nums[2 * nPos + 2]);
                sink(nums, 2 * nPos + 2, nSize);
            }    
        } 
        else if (nums[nPos] > min(nums[2 * nPos + 1], nums[2 * nPos + 2]))
        {
            swap(nums[nPos], nums[2 * nPos + 1]);
            sink(nums, 2 * nPos + 1, nSize);
        }       
    }

    void MakeHeap(int k, vector<int>& nums)
    {
        int nSize = nums.size();
        int i = (nSize - 1) / 2;

        while(i >= 0)
        {
            sink(nums, i, nSize);
            i--;
        }
    }

    void SortK(int k)
    {

    }
private:

    vector<int> topK;
    int nSize;
};