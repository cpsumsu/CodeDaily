#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int ans = 0, n = nums.size(), l = 0, cnt = 1;
        for (int r = 0; r < n; ++r)
        {
            cnt *= nums[r];
            while(cnt >= k)
            {
                cnt /= nums[l];
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};
int main()
{
   return 0;
}