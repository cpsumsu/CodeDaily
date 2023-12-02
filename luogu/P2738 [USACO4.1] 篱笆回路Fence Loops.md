---
Difficulty: "提高+/省选−"
tags: ["最小環", "floyd算法"]
---

> Problem: [P2738 [USACO4.1] 篱笆回路Fence Loops](https://www.luogu.com.cn/problem/P2738)

# 思路
- 一道關於最小環以及floyd算法的題目，參考資料如下: 
- https://oi-wiki.org/graph/min-cycle/
- https://oi-wiki.org/graph/shortest-path/#floyd-%E7%AE%97%E6%B3%95
- 重點還是初始化最短路矩阵這一步

# 复杂度
- 时间复杂度:
> $O(n^3)$

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
const int INF = 1e9;
const int N = 1e5 + 10; // 用於定義常量數組
#define MAXN ((int) 1e5) //
#define MAXM ((int) 1e5)
#define MAXPROD ((int) 1e5)

int n;
vector<int> l[225], r[225];
int len[225], mp[225][225], dis[225][225];

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n;
	// 最小環
	// 建圖
	for (int i = 0; i < n; ++i)
	{
		int s, ls, ns1, ns2;
		cin >> s >> ls >> ns1 >> ns2;
		len[s] = ls;
		for (int j = 0; j < ns1; ++j)
		{
			int t; cin >> t; l[s].push_back(t);
		}
		for (int j = 0; j < ns2; ++j)
		{
			int t; cin >> t; r[s].push_back(t);
		}
	}
	// https://oi-wiki.org/graph/min-cycle/
	// init mp[i][j] 最大值
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			mp[i][j] = INF;
	// init mp[i][左右端點]: 增加長度
	for (int i = 1; i <= n; ++i)
	{
		for (auto a : l[i])
			mp[i][a] = len[i] + len[a];
		for (auto a : r[i])
			mp[i][a] = len[i] + len[a];
	}
	// init 初始化最短路矩阵
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			dis[i][j] = mp[i][j];
	// floyd
	int ans = INF;
	for (int i = 1; i <= n; ++i)
	{
		// https://oi-wiki.org/graph/shortest-path/#floyd-%E7%AE%97%E6%B3%95
		for (auto a : l[i])
		{
			if (a < i)
			{
				for (auto b : r[i])
				{
					if (b < i)
						ans = min(ans, dis[a][b] + mp[a][i] + mp[b][i]);
				}
			}
		}
		// 更新最短路矩阵
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
	}
	// cout << "ok" << endl;
	// 計算出環周長／２

	cout << ans / 2 << endl;
	return 0;
}
```