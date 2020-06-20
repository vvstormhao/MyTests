#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> st;
        int nSize = int(nums.size());
        for (int i = 0; i < nSize; ++i)
        {
            auto it = st.find(nums[i]);
            if (st.end() == it)
            {
                st.insert(nums[i]);
            }
            else
            {
                st.erase(it);
            }
        }

        return *st.begin();
    }
};