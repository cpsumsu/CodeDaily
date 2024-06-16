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
    vector<int> singleNumber(vector<int>& nums) {
        // unordered_map<int,int> mp;
        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     mp[nums[i]]++;
        // }
        // vector<int> ans;
        // for (auto& [u,v] : mp) if (v == 1) ans.push_back(u);
        // return ans; 
        int xorx = 0;
        for (auto i : nums) xorx ^= i;
        unsigned int lowerb = xorx & -(unsigned int)xorx;
        vector<int> ans(2, 0);
        for (auto i : nums)
        {
            if ((lowerb & i) == 0)
                ans[0] ^= i;
            else
                ans[1] ^= i;
        }
        return ans;
    }
};
int main()
{
   return 0;
}