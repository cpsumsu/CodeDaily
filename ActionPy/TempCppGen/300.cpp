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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n,1);
        for(int i=0; i<n;i++){
            for(int j =0; j<i; j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[j]+1,dp[i]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
int main()
{
   return 0;
}