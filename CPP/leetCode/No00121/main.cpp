#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX;
        int maxProfit = INT_MIN;
        int nSize = prices.size();
        for (int i = 0; i < nSize; ++i)
        {
            if (prices[i] < minVal)
            {
                minVal = prices[i];
            }
            else
            {
                int profit = prices[i] - minVal;
                if ( profit > maxProfit)
                {
                    maxProfit = profit;
                }
            }
            
        }

        return maxProfit > 0 ? maxProfit : 0;
    }
};