#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = nums[0];
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i < n; ++i)
        {
            // 隊頭出隊
            while(dq.front() + k < i)
                dq.pop_front();
            
            // 更新 dp[i]
            dp[i] = nums[i] + dp[dq.front()];

            // 隊尾出隊
            while(!dq.empty() && dp[dq.back()] <= dp[i])
                dq.pop_back();
            dq.push_back(i);
        }
        return dp[n - 1];
    }
};