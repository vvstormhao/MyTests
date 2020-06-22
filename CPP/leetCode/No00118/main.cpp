#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> ret;
      vector<int> pre;
      for (int i = 1; i <= numRows; ++i)
      {
          auto r = generate(pre, i);
          pre = r;
          ret.push_back(r);
      }  

      return ret;
    }
private:
    vector<int> generate(vector<int> pre, int numRows)
    {
        vector<int> ret;
        if (1 == numRows)
        {
            ret.push_back(1);
            return ret;
        }

        ret.push_back(pre[0]);
        for (int i = 1; i < numRows - 1; ++i)
        {
            ret.push_back(pre[i - 1] + pre[i]);
        }
        ret.push_back(pre[numRows - 2]);

        printf("numRows %d return : ", numRows);
        auto itInStart = ret.begin();
        auto itInEnd = ret.end();

        for (; itInStart != itInEnd; ++itInStart)
        {
           printf("%d ", *itInStart); 
        }
        printf("\n");
        return ret;
    }
};

int main()
{
    Solution s;
    auto rst = s.generate(5);
    auto itOutStart = rst.begin();
    auto itOutEnd = rst.end();
    for (; itOutStart != itOutEnd; ++itOutStart)
    {
        auto itInStart = (*itOutStart).begin();
        auto itInEnd = (*itOutStart).end();

        for (; itInStart != itInEnd; ++itInStart)
        {
           printf("%d ", *itInStart); 
        }

        printf("\n");
    }
    return 1;
}