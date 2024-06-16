#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <functional>
#include <limits.h>
using namespace std;


class Solution_a {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        for (int i = 0, cnt1 = 0; i < s.size(); ++i)
        {
            if (s[i] == '1') cnt1++;
            else ans+= cnt1;
        }
        return ans;
    }
};
int main()
{
   return 0;
}