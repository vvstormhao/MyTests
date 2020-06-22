#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int nSize = s.length();
        int rk = 0; // 指向子串的后边界
        int ans = 0; // 结果

        unordered_set<char> st;
        for (int i = 0; i < nSize; ++i)
        {
            while(rk < nSize && 0 == st.count(s[rk]))
            {
                rk++;
                st.insert(s[rk]);
            }
            if (i > 0) st.erase(s[i - 1]);
            ans = max(ans, rk - i + 1);
        }

        return ans;

    }
    int lengthOfLongestSubstring1(string s) {
        int n = s.length();
        if (0 == n || 1 == n)
        {
            return n;
        }

        unordered_map<char, int> st;
        vector<int> vec;
        int i = 0;
        while (i < n)
        {
            if(0 == st.count(s[i]))
            {
                st[s[i]] = i;
                ++i;
            }
            else
            {
                int nIndex = st[s[i]];
                i = nIndex + 1;
                vec.push_back(st.size());
                st.clear();
            }
        }
        vec.push_back(st.size());

        int nMax = 0;
        n = vec.size();

        for (int i = 0; i < n; ++i)
        {
            if (vec[i] > nMax)
            {
                nMax = vec[i];
            }
        }

        return nMax;
    }
};