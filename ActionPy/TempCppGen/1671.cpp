#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> pre(n), r;
        for (int i = n - 1; i ; --i)
        {
            int var = nums[i];
            auto it = lower_bound(r.begin(), r.end(), var);
            pre[i] = it - r.begin() + 1;
            if (it == r.end()) r.emplace_back(var);
            else *it = var;
        }
        r.clear();
        for (int i = 0; i < n - 1; ++i)
        {
            int var = nums[i];
            auto it = lower_bound(r.begin(), r.end(), var);
            int ppre = it - r.begin() + 1;
            if (it == r.end()) r.emplace_back(var);
            else *it = var;
            if (ppre >= 2 && pre[i] >= 2)
                ans = max(ans, ppre + pre[i] - 1);
        }
        return n - ans;
    }
};