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
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int,int> mp;
        for (auto x : nums) mp[x]++;
        int n = moveFrom.size();
        for (int x = 0; x < n; ++x)
        {
            if (mp[moveFrom[x]])
            {
                auto t = mp[moveFrom[x]];
                mp[moveFrom[x]] = 0;
                mp[moveTo[x]] += t;
            }
        }
        vector<int> ans;
        for (auto& [u,v] : mp) if (v > 0) ans.push_back(u);
        return ans;
    }
};
int main()
{
   return 0;
}