#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    int maxOperations(vector<int>& nums) {
        int s = -1, ans = 0;
        while(nums.size() > 1)
        {
            int p = nums[1] +  nums[0];
            // cout << p << endl;
            if (s != p && s != -1) break;
            s = p;
            ans++;
            nums.erase(nums.begin(), nums.begin() + 2);
        }
        return ans;
    }
};