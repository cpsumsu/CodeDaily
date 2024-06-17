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
    int maximumCount(vector<int>& nums) {
        int p = 0, n = 0;
        for (auto a : nums) if (a > 0) p++; else if (a < 0) n++;
        return max(p, n);
    }
};

class Solution_b {
public:
    int maximumCount(vector<int>& nums) {
        int p = ranges::lower_bound(nums, 0) - nums.begin();
        int n = nums.end() - ranges::upper_bound(nums, 0);
        return max(p, n);
    }
};
int main()
{
   return 0;
}