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
    long long maxArrayValue(vector<int>& nums) {
        long long ans = nums.back();
        int n = nums.size();
        // for (int i = 0; i < n; ++i)
        // {
        //     long long res = nums[i];
        //     for (int j = i - 1 ; j >= 0; --j)
        //         if (nums[j] <= res) res += nums[j];
        //     ans = max(ans, res);
        // }
        for (int j = n - 2; j >= 0; --j)
            ans = ans >= nums[j] ? ans + nums[j] : nums[j];
        return ans;
    }
};
int main()
{
   return 0;
}