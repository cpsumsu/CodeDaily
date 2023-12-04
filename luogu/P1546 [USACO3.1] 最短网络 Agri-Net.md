---
Difficulty: "普及−"
tags: ["Prim 算法"]
---

> Problem: [P1546 [USACO3.1] 最短网络 Agri-Net](https://www.luogu.com.cn/problem/P1546)

# 思路
- Prim 算法

# 复杂度
- 时间复杂度:
> $O(n^2)$

- 空间复杂度:
> $O(n^2)$
  
# Code
```C++ 
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
// #include <map>
using namespace std;

typedef long long LL;
typedef long long int lli;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x7f7f7f7f; // 最大值2139062143。用於代替INT_MAX 
const int N = 114; // 用於定義常量數組
#define MAXN ((int) 1e5) //
#define MAXM ((int) 1e5)
#define MAXPROD ((int) 1e5)

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int moves[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }; // 4向移動
// int moves[8][2] = { {0,1},{1,0},{-1,0},{0,-1}, {1,1},{-1,1},{1,-1},{-1,-1} }; // 8向移動
// int moves[6][2] = { {0,1},{1,0},{1,-1},{0,-1},{-1,0},{-1,1} }; // 六邊移動 (網格六邊形專用)

int main()
{
    // 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    vector<vector<int>> g(N, vector<int>(N));
    vector<bool> vis(N, false);
    vector<int> a(N, INF);
    a[1] = 0;
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        for (int j = 1; j <= t; ++j)
        {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= t; ++i)
    {
        int idx = 0;
        for (int j = 1; j <= t; ++j)
            if (!vis[j] && a[j] < a[idx]) idx = j;
        vis[idx] = true;
        for (int j = 1; j <= t; ++j)
            if (!vis[j] && g[idx][j] < a[j]) a[j] = g[idx][j];
    }
    for (int i = 1; i <= t; ++i) ans += a[i];
    cout << ans << endl;
    return 0;
}
```