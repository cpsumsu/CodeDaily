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
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> ue;
        vector<int> pre(n + 1);
        for (int i = n - 1; i >= 0; --i)
        {
            ue.insert(nums[i]);
            pre[i] = ue.size();
        }
        ue.clear();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            ue.insert(nums[i]);
            ans[i] = ue.size() - pre[i + 1];
        }
        return ans;
    }
};
int main()
{
   return 0;
}