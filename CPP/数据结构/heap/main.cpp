#include <iostream>
#include <vector>

#include <iostream>
#include <vector>

using namespace std;

void swim(vector<int> &nums, int nIndex)
{
    if (nums[nIndex / 2] < nums[nIndex])
    {
        swap(nums[nIndex], nums[nIndex / 2]);
    }
}

void sink(vector<int> &nums, int nIndex, int nRange)
{
    int n = nRange;
    int l = 2 * nIndex;
    int r = 2 * nIndex + 1;
    if (min(l, r) > n - 1)
    {
        return;
    }

    if (r < n)
    {
        int rl = nums[l];
        int rr = nums[r];
        if (nums[nIndex] < max(rl, rr))
        {
            int nTarget = rl > rr ? l : r;
            swap(nums[nIndex], nums[nTarget]);
            sink(nums, nTarget, n);
        }
    }
    else
    {
        int rl = nums[l];
        if (nums[nIndex] < rl)
        {
            swap(nums[nIndex], nums[l]);
        }        
    }
}

void heapPrint(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void makeHeap(vector<int> &nums)
{
    int n = nums.size() / 2;
    int nSzie = nums.size();
    while (n > 0)
    {
        sink(nums, n, nSzie);
        n--;
    }
}

void Insert(vector<int> &nums, int val)
{
    nums.push_back(val);
    int n = nums.size() - 1;
    swap(nums[1], nums[n]);
}

void HeapSort(vector<int> &nums)
{
    int n = nums.size() - 1;

    while(n > 0)
    {
        swap(nums[1],nums[n]);
        sink(nums,1, n--);
    }
}

int main()
{
    vector<int> vec = {-1, 10, 5, 35, 90, 27, 2, 9, 30, 25};
    makeHeap(vec);
    heapPrint(vec);

    Insert(vec, 22);
    heapPrint(vec);

    //HeapSort(vec);
    //heapPrint(vec);

}