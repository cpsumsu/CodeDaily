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
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](const int a, const int b)
        {
            return nums2[a] < nums2[b];
        });

        vector<int> dp(n + 1);
        for (int i = 0; i < n; ++i)
        {
            int x = nums1[idx[i]], y = nums2[idx[i]];
            for (int j = i + 1; j ; --j)
            {
                // 不選: 選 dp[j]
                // 選: 枚舉 j ，選中 j - 1 個下標，減少量最大是多少
                dp[j] = max(dp[j], dp[j - 1] + x + y * j);
            }
        }

        int p1 = accumulate(nums1.begin(), nums1.end(), 0);
        int p2 = accumulate(nums2.begin(), nums2.end(), 0);
        for (int t = 0; t <= n; ++t)
        {
            if (p1 + p2 * t - dp[t] <= x)
            {
                return t;
            }
        }

        return -1;
    }
};
int main()
{
   return 0;
}