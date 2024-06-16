#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0, n = nums.size();
        // 1 2 3 5 6
        int m = unique(nums.begin(), nums.end()) - nums.begin();
        int l = 0;
        for (int i = 0; i < m; ++i)
        {
            while(nums[l] < nums[i] - n + 1)
                l++;
            cnt = max(cnt, i - l);
        }
        return n - cnt - 1;
    }
};