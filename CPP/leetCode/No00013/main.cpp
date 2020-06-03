#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> roma2int = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        std::unordered_map<char, std::unordered_set<char>> postChars = {{'I',{'V','X'}}, {'X',{'L','C'}}, {'C', {'D', 'M'}}};

        int final = 0;
        int nCount = 0;
        char cLast;
        for (auto nIndex = 0;nIndex < s.length(); nIndex++)
        {
            if (0 == roma2int.count(s[nIndex]))
            {
                return 0;
            }
            if (nCount >= 3)
            {
                return 0;
            }

            if (cLast == s[nIndex])
            {
                nCount++;
            }
            else
            {
                nCount = 0;
            }

            cLast = s[nIndex];

            auto cur = roma2int[s[nIndex]];
            auto next = roma2int[s[nIndex + 1]];
            
            if (cur < next)
            {
                if (0 == postChars.count(s[nIndex]))
                {
                    return 0;
                }
                else
                {
                    auto it = postChars.find(s[nIndex]);
                    if (0 == it->second.count(s[nIndex + 1]))
                    {
                        return 0;
                    }
                    else
                    {
                        final -= cur;
                    }
                }
            }
            else 
            {
                final += cur;    
            }
        }
    }

    int romanToInt1(std::string s) {
        std::unordered_map<char, int> roma2int = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};

        int final = 0;
        for (auto nIndex = 0;nIndex < s.length(); nIndex++)
        {
            if (0 == roma2int.count(s[nIndex]))
            {
                return 0;
            }

            auto cur = roma2int[s[nIndex]];
            auto next = roma2int[s[nIndex + 1]];
            
            if (cur < next)
            {
                final -= cur;
            }
            else 
            {
                final += cur;    
            }
        }
    }
};