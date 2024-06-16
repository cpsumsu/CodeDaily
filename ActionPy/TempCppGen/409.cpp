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
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for (int i = 0; i < s.size(); ++i)
        {
            char ch = s[i];
            if (mp.find(ch) != mp.end())
                mp[ch]++;
            else
                mp[ch] = 1;
        }
        int ans = 0;
        bool bb = false;
        for (auto& [u,v] : mp)
        {
            if (v % 2 == 0)
                ans += v;
            else
            {
                ans += v;
                if (!bb) bb = true;
                else ans -= 1;
            }
        }
        return ans;
    }
};
int main()
{
   return 0;
}