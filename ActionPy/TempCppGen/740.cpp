#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int deleteAndEarn(vector<int>& nums) {
        int dp[10001]={0};
        for(int i=0;i<nums.size();i++){
            dp[nums[i]] += nums[i];
        }
        for(int i=2; i<10001; i++ ){
            dp[i] = max(dp[i-1],dp[i-2]+dp[i]);
        }
        return dp[10000];
    }
};