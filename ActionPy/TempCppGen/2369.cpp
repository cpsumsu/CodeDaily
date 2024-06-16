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
    bool validPartition(vector<int>& nums) {
        // 划分子問題
        int n = nums.size();
        // dp[i+1] 是 num[0] ~ num[i] 能不能有效 
        vector<bool> dp(n + 1, false); //空數組也是一個狀態
        dp[0] = true;
        for (int i = 1; i < n; ++i)
        {
            int x = nums[i];
            if (dp[i-1] && x == nums[i - 1])
                dp[i+1] = true;
            if (i > 1)
            {
                if (dp[i-2] && x == nums[i - 1] && x == nums[i - 2])
                    dp[i+1] = true;
                if (dp[i-2] && x == nums[i - 1] + 1 && x == nums[i - 2] + 2)
                    dp[i+1] = true;
            }
        }
        return dp[n];
    }
};
int main()
{
   return 0;
}