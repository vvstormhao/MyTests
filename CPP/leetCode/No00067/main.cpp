#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int aSize = a.size() - 1;
        int bSize = b.size() - 1;

        int t = 0;
        string result;
        while(aSize >=0 || bSize >=0)
        {
            if (aSize >=0 && a[aSize] == '1') t++;
            if (bSize >= 0 && b[aSize] == '1') t++;

            result += '0' + t % 2;
            t = t/2;
            aSize--;
            bSize--;
        }

        if (t > 0) result += '0' + t%2;
        reverse(result.begin(), result.end());
        return result;
    }
};