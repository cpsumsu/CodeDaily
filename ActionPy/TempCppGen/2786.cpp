#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> dp(n, 0);
        for (int i = n - 1; i >= 0; --i)
        {
            long long b = nums[i] % 2;
            dp[b] = max(dp[b], dp[b ^ 1] - x) + nums[i];
        }
        return dp[nums[0] % 2];
    }
};
int main()
{
   return 0;
}