#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (0 == isalnum(s[i]))
            {
                ++i;
                continue;
            }
            else
            {
                s[i] = tolower(s[i]);
            }
            

            if (0 == isalnum(s[j]))
            {
                --j;
                continue;
            }
            else
            {
                s[j] = tolower(s[j]);
            }

            if (s[i++] != s[j--])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    string s = "A man, a plan, a canal: Panama";
    Solution so;
    bool b = so.isPalindrome(s);
    printf("b is %d\n", b);
}