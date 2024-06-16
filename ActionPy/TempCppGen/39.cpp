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
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(vector<int>& nums, int sum, int target, int st)
    {
        if (sum == target)
        {
            ret.push_back(path);
        }
        if (sum >= target)
        {
            return;
        }
        for (int i = st; i < nums.size();++i)
        {
            path.push_back(nums[i]);
            dfs(nums,sum + nums[i],target, i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,0,target,0);
        return ret;
    }
};
int main()
{
   return 0;
}