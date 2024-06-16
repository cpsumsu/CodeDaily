#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size(), ans = nums[k], mn = nums[k];
        int l = k, r = k;
        for (int t = 0; t < n - 1; ++t)
        {
            if (r == n - 1 || l > 0 && nums[l - 1] > nums[r + 1])
            {
                l--;
                mn = min(mn, nums[l]);
            }
            else
            {
                r++;
                mn = min(mn, nums[r]);
            }
            ans = max(ans, mn * (r - l + 1));
        }
        return ans;
    }
};