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
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size();++i)
        {
            ans += abs(nums[nums.size()/2] - nums[i]);
        }
        return ans;
    }
};

class Solution_b {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size()/2;++i)
        {
            ans += nums[nums.size()/2] - nums[i];
        }
        for (int i = nums.size()/2 + 1; i < nums.size();++i)
        {
            ans += nums[i] - nums[nums.size()/2];
        }
        return ans;
    }
};
int main()
{
   return 0;
}