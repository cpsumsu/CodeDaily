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
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++)
        {
            int x = nums[i];
            if (i > 0 && x == nums[i - 1])
                continue;
            int j = i + 1, k = n - 1;
            while(j < k)
            {
                int y = x + nums[j] + nums[k];
                if (y == 0)
                {
                    ans.push_back({x, nums[j] , nums[k]});
                    j++;
                    while(j < k && nums[j] == nums[j - 1])
                        j++;
                    k--;
                    while(k > j && nums[k] == nums[k + 1])
                        k--;
                }
                    
                else if (y < 0)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};
int main()
{
   return 0;
}