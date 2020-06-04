#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;
class Solution
{
public:
    bool isValid(string s) {
        unordered_set<char> pushChar = {'(', '{', '['};
        unordered_map<char, char> dit = {{')','('},{'}','{'},{']','['}};
        auto itEnd = dit.end();
        stack<char> st;
        for (auto &s : s)
        {
            if (0 != pushChar.count(s))
            {
                st.push(s);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }

                auto it = dit.find(s);
                if (it != itEnd &&it->second == st.top() )
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }  
        }

        return st.empty() ? true : false;
    }
};

int main()
{
    Solution s;
    bool bVal = s.isValid("([)]");
    printf("is Valid %d\n", bVal);
    return 1;
}