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
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> p1(n, 1), p2(n, 1);
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > nums[i - 1])
                p1[i] += p1[i - 1];
            if (nums[i] < nums[i - 1])
                p2[i] += p2[i - 1];
        }
        int ans = 0;
        for (auto& a : p1) ans = max(ans, a);
        for (auto& a : p2) ans = max(ans, a);
        return ans;
    }
};
int main()
{
   return 0;
}