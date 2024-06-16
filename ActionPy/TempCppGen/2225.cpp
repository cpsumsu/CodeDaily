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
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> mp;
        for (auto& a : matches)
        {
            mp[a[1]]++;
            if (!mp[a[0]])
                mp[a[0]] = 0;
        }
        vector<vector<int>> ans(2);
        for (auto& [u,v] : mp)
        {
            if (v == 0) ans[0].push_back(u);
            else if (v == 1) ans[1].push_back(u);
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};
int main()
{
   return 0;
}