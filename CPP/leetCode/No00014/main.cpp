#include <vector>
#include <string>
#include <memory.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto vs = strs.size();
        if (0 == vs)
        {
            return "";
        }
        std::string pat = strs[0];
        int nMinSize = pat.size();
        for (auto &s : strs)
        {
            auto &&ns = s.size();
            if (ns < nMinSize)
            {
                nMinSize = ns;
                pat = s;
            }
        }

        if (0 == nMinSize)
        {
            return "";
        }
        
        for (auto nIndex = 0; nIndex < nMinSize; ++nIndex)
        {
            for(auto &s : strs)
            {
                if(s[nIndex] != pat[nIndex])
                {
                    return nIndex == 0 ? "" : pat.substr(0, nIndex);
                }
            }
        }

        return pat;     
    }
};

int main()
{
    vector<string> strs = {"ab","cac"};
    Solution s;
    string &&rst = s.longestCommonPrefix(strs);
    printf("result is %s\n", rst.c_str());
}