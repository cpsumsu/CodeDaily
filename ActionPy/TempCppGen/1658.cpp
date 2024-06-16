#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int minOperations(vector<int>& nums, int x) {
        // 逆轉思路，移除最長的子數組，使剩下的數和為x
        int ans = -1, n = nums.size(), l = 0, target = 0, s = 0;
        for (auto a : nums) target+=a;
        target -= x;
        if (target < 0) return -1;
        for (int r = 0; r < n; ++r)
        {
            int yy = nums[r];
            s += yy;
            while(s > target)
            {
                int k = nums[l];
                s -= k;
                l++;
            }
            if (s == target)
                ans = max(ans, r - l + 1);
        }
        return ans < 0 ? -1 : n - ans;
    }
};
int main()
{
   return 0;
}