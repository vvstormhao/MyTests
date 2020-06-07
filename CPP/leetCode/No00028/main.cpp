#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        return KMP(haystack, needle);
    }
    void GetNext(string &needle, int *pNext, int arrySize)
    {
        if (nullptr == pNext || 0 == arrySize)
        {
            return;
        }

        int i = 0;
        int j = 1;
        pNext[0] = 0;
        auto nSize = needle.size();
        while (j < nSize)
        {
            if (needle.at(i) == needle.at(j))
            {
                printf("i is %d, j is %d, needle[i] is %c, needle[j] is %c", i, j, needle.at(i), needle.at(j));
                pNext[j] = pNext[j - 1] + 1;
                printf("next %d is %d\n", j, pNext[j]);

                ++i;
                ++j;
            }
            else
            {
                printf("look for pNest[%d - 1]   ", j);
                j = pNext[j-1];
                printf("j now is %d\n", j);
            }
            
        }
    }
    int KMP(string &haystack, string &needle)
    {
        const int nHayStackSize = haystack.size();
        const int nNeedleSize = needle.size();
        int next[nNeedleSize];
        GetNext(needle, next, nNeedleSize);

        int i = 0, j = 0;
        while (i < nHayStackSize && j < nNeedleSize)
        {
            if (haystack.at(i) == needle.at(j))
            {
                ++i;
                ++j;
            }
            else
            {
                j = next[j];
            }
            
        }

        
        return j == nNeedleSize ? j - i : -1 ;
    }

    int ViolentMatch(string &haystack, string needle){
        int nHayStackSize = haystack.size();
        int nNeedleSize = needle.size();

        if (0 == nHayStackSize || 0 == nNeedleSize || nNeedleSize > nHayStackSize)
        {
            return -1;
        }

        int i = 0, j = 0;
        while (i < nHayStackSize && j < nNeedleSize)
        {
            if (haystack.at(i) != needle.at(j))
            {
                j = 0;
                i = i - j + 1;
            }
            else
            {
                ++i;
                ++j;
            }  
        }

        return j != nNeedleSize ? -1 : i - j;   
    }
};

int main() 
{
    Solution s;

    string neddle = "abcdabca";
    int *pNext = new int(neddle.size());
    s.GetNext(neddle, pNext, neddle.size());
    for (auto i = 0; i < neddle.size(); ++i)
    {
        printf("%d ", pNext[i]);
    }
    printf("\n");
    return 1;
}