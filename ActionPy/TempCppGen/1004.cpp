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
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, n = nums.size(), l = 0, cnt0 = 0;
        for (int r = 0; r < n; ++r)
        {
            int x = nums[r];
            if (x == 0) cnt0++;
            while(cnt0 > k)
            {
                int y = nums[l];
                if (y == 0) cnt0--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
int main()
{
   return 0;
}