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
    int maxSubArray(vector<int>& nums) {
        int s = 0, ans = nums[0];
        for (auto a : nums)
        {
            if (s > 0)
                s += a;
            else
                s = a;
            ans = max(ans, s);
        }
        return ans;
    }
};
int main()
{
   return 0;
}