#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
using LL = long long;


class Solution_a {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        vector<vector<int>> g(edges.size() + 1);
        for (auto& e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        unordered_set<LL> s;
        for (auto& g: guesses)
        {
            s.insert((LL) g[0] << 32 | g[1]);
        }

        int ans = 0, cnt0 = 0;
        function<void(int, int)> dfs = [&](int x, int fa)
        {
            for (int y : g[x])
            {
                if (y != fa)
                {
                    cnt0 += s.count((LL) x << 32 | y);
                    dfs(y, x);
                }
            }
        };
        dfs(0, -1);
        
        function<void(int,int,int)> rer = [&](int x, int fa, int cnt)
        {
            ans += cnt >= k;
            for (int y : g[x])
            {
                if (y != fa)
                {
                rer(y, x, cnt 
                    - s.count((LL) x << 32 | y)
                    + s.count((LL) y << 32 | x)
                    );
                }
            }
        };
        rer(0 , -1, cnt0);
        return ans;
    }
};
int main()
{
   return 0;
}