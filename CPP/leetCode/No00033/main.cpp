#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string ret = countAndSay(n - 1);
        int strSize = ret.size();
        int nCount = 1; 
        string retStr;
        for (int i = 0; i < strSize; ++i)
        {
            if (i + 1 < strSize && ret.at(i) == ret.at(i + 1))
            {
                nCount++;
            } else {
                retStr += to_string(nCount) + ret.at(i);
                nCount = 1;
            }
        }

        return retStr;
    }
};

int main()
{
    Solution s;
    auto ret1 = s.countAndSay(1);
    printf("ret1 is %s\n", ret1.c_str());

    auto ret2 = s.countAndSay(2);
    printf("ret2 is %s\n", ret2.c_str());

    auto ret3 = s.countAndSay(3);
    printf("ret3 is %s\n", ret3.c_str());

    auto ret4 = s.countAndSay(4);
    printf("ret4 is %s\n", ret4.c_str());

    auto ret5 = s.countAndSay(5);
    printf("ret5 is %s\n", ret5.c_str());
}