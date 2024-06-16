#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 1;i < nums.size(); ++i)
        {
            int res = lower_bound(nums.begin(), nums.begin() + i, target - nums[i]) - nums.begin();
            ans += res;
        }
        return ans;
    }
};

class Solution_b {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, r = n - 1, ans = 0;
        while(l < r)
        {
            int x = nums[l] + nums[r];
            if (x < target)
            {
                ans += r - l;
                l++;
            }
            else 
                r--;
        }
        return ans;
    }
};
int main()
{
   return 0;
}