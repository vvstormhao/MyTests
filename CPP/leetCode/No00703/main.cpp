#include <iostream>
#include <vector>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) 
    : nSize(k)
    {
        MakeHeap(nSize, nums);
        SortK();
        PrintTopK();
    }
    
    int add(int val) {
        return 1;
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

        int nRange = min(int(nums.size()), k);

        for (int j = 0; j < nRange; j++)
        {
            topK.push_back(nums[j]);
        }
    }

    void SortK()
    {
        vector<int> tmp;
        int k = nSize;
        while (k >= 0)
        {
            tmp.push_back(topK[k]);
            swap(topK[0], topK[k]);
            sink(topK, 0, k - 1);
            --k;
        }

        topK = tmp;
    }

    void PrintTopK()
    {
        auto itBegin = topK.begin();
        auto itEnd = topK.end();
        for (; itBegin != itEnd; ++itBegin)
        {
            printf("%d ", *itBegin);
        }
        printf("\n");
    }
private:

    vector<int> topK;
    int nSize;
};

int main()
{
    vector<int> vec = {3,7,5,1,15,90,45,6,23};
    KthLargest *p = new KthLargest(5, vec);
    delete p;
    return 1;
}