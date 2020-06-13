#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
       int nSize = int(s.size());

       if (0 == nSize)
       {
           return 0;
       } 

       const char *pStr = s.c_str();
       int nLength = 0;
       for (int nIndex = nSize - 1; nIndex >= 0; nIndex--)
       {
           if (' ' == pStr[nIndex] && nLength == 0)
           {
               continue;
           } 
           else if (' ' != pStr[nIndex])
           {
               nLength++;
           }
           else 
           {
               break;
           }
        }

        return nLength;
    }
};

int main()
{
    string cmpStr = "Hello World War II    ";
    Solution s;
    int nLenght = s.lengthOfLastWord(cmpStr);
    printf("length is %d\n", nLenght);
}