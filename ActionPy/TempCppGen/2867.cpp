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
const int MX = 1e5;
bool np[MX + 1];
int init = []() {
    np[1] = true;
    for (int i = 2; i * i <= MX; ++i)
    {
        if (!np[i])
        {
            for (int j = i * i; j <= MX; j += i)
                np[j] = true;
        }
    }
    return 0;
}();



class Solution_a {
public:

    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n + 1);
        for (auto &e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> size(n + 1);
        vector<int> ndoes;
        function<void(int,int)> dfs = [&](int x, int fa)
        {
            ndoes.push_back(x);
            for (int y : g[x])
            {
                if (y != fa && np[y])
                    dfs(y, x);
            }
        };
        long long ans = 0;

        for (int x = 1; x <= n; ++x)
        {
            if (np[x]) continue;
            int s = 0;
            for (int y : g[x])
            {
                if (!np[y]) continue;
                if (size[y] == 0)
                {
                    ndoes.clear();
                    dfs(y, -1);
                    for (int z : ndoes)
                        size[z] = ndoes.size();
                }
                ans += (long long) size[y] * s;
                s += size[y];
            }
            ans += s;
        }
        return ans;
    }
};
int main()
{
   return 0;
}