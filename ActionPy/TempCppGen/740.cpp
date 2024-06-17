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
int main()
{
   return 0;
}