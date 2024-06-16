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
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> r;
        function<void(int,int,int)> dfs = [&](int p, int s, int cnt) {
            if (p > 10 || s > n || cnt > k) return;
            if (cnt == k && s == n)
            {
                ans.push_back(r);
                return;
            }
            r.push_back(p);
            dfs(p + 1, s + p, cnt + 1);
            r.pop_back();
            dfs(p + 1, s, cnt);
        };
        dfs(1, 0, 0);
        return ans;
    }
};
int main()
{
   return 0;
}