// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍


#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <vector>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {

        std::vector<int> result;
        if (nums.size() < 2)
        {
            return result;
        }

        auto begin = nums.begin();
        auto itBegin = begin;
        auto end = nums.end();

        std::unordered_map<int, int> hMap;
        for (; begin != end; ++begin)
        {
            auto it = hMap.find(target - *begin);
            if (it == hMap.end())
            {
                hMap.insert(std::pair<int, int>(*begin, begin - itBegin));
            }
            else
            {
                result.push_back(it->second);
                result.push_back(begin - itBegin);
            }
        }  

        return result; 
    }
};

int main()
{
    std::vector<int> source = {1,3,5,6,7,9};
    int target = 9;

    Solution s;
    auto ret = s.twoSum(source, target);
    auto size = ret.size();
    printf("ret size is %d\n", size);
    
    for (auto n : ret)
    {
        printf("%d\n", n);
    }
}