#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int balancedString(string s) {
        int ans = INT_MAX, n = s.size(), l = 0, m = n / 4;
        unordered_map<char,int> um;
        for (auto ch : s) um[ch]++;
        if (um['Q'] == m && um['W'] == m && um['E'] == m && um['R'] == m) return 0;
        for (int r = 0; r < n; ++r)
        {
            char x = s[r];
            --um[x];
            while(um['Q'] <= m && um['W'] <= m && um['E'] <= m && um['R'] <= m)
            {
                ans = min(ans, r - l + 1);
                char y = s[l];
                ++um[y];
                l++;
            }
        }
        return ans;
    }
};
int main()
{
   return 0;
}