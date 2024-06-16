#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0, cnt = 0, ans = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            cnt += nums[i];
            while(cnt >= target)
            {
                ans = min(ans, i - l + 1);
                cnt -= nums[l];
                l++;
            }
        }
        if (ans == INT_MAX) return 0;
        return ans;
    }
};