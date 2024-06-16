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
    int lengthOfLongestSubstring(string s) {
        int ans = 0, n = s.size();
        int l = 0;
        unordered_map<char,int> m;
        for (int r = 0; r < n; ++r)
        {
            m[s[r]]++;
            while (m[s[r]] > 1)
            {
                m[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
int main()
{
   return 0;
}