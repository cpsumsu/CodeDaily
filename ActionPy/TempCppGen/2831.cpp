#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <functional>
#include <limits.h>
#include <unordered_set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <string.h>
#include <numeric>
#include <cassert>
#include <cmath>
#include <cstdint>
using namespace std;


class Solution_a {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            mp[nums[i]].push_back(i - mp[nums[i]].size());
        int ans = 0;
        for (auto& [u,v] : mp)
        {
            int l = 0;
            for (int r = 0; r < v.size(); ++r)
            {
                while(v[r] - v[l] > k)
                    l++;
                ans = max(ans, r - l + 1);
            }   
        }
        return ans;
    }
};
int main()
{
   return 0;
}