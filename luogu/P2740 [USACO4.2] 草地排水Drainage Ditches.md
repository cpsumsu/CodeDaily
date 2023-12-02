---
Difficulty: "提高+/省选−"
tags: ["最大流"]
---

> Problem: [P2740 [USACO4.2] 草地排水Drainage Ditches](https://www.luogu.com.cn/problem/P2740)

# 思路
- 用 bfs 找點與點之間的距離，看看有沒有增廣路
- 用 dfs 增加流量
- 最大流算法的應用，基本原理是DFS和BFS一起使用的，參考資料:
- https://www.desgard.com/algo/docs/part4/ch03/1-maximum-flow-basic/

# 复杂度
- 时间复杂度:
> $O(nm)$

- 空间复杂度:
> $O(nm)$
  
# Code
```C++ 
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string.h>
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
const int N = 1e5 + 10; // 用於定義常量數組
#define MAXN ((int) 1e5) //
#define MAXM ((int) 1e5)
#define MAXPROD ((int) 1e5)


int n, m;
int mp[205][205], dis[205];

bool bfs()
{
	queue<int> q;
	memset(dis, -1, sizeof(dis));
	q.push(1);
	dis[1] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= m; ++i)
		{
			if (mp[cur][i] && dis[i] < 0)
			{
				dis[i] = dis[cur] + 1;
				q.push(i);
			}
		}
	}
	if (dis[m] > 0) return true;
	return false;
}

int dfs(int x, int y)
{
	// x == m : 到流入點
	if (x == m) return y;
	for (int i = 1; i <= m; ++i)
	{
		if (mp[x][i] && dis[i] == dis[x] + 1)
		{
			// 
			int cur = dfs(i, min(y, mp[x][i]));
			if (cur)
			{
				mp[x][i] -= cur;
				mp[i][x] += cur;
				return cur;
			}
		}
	}
	return 0;
}

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int x, y, val;
		cin >> x >> y >> val;
		mp[x][y] += val;
	}

	int ans = 0;
	// bfs + dfs: 最大流量
	// 用 bfs 找點與點之間的距離，看看有沒有增廣路
	// 用 dfs 增加流量
	while (bfs())
	{
		// cout << "ok" << endl;
		int res = dfs(1, INF);
		// cout << res << endl;
		if (res) ans += res;
	}
	cout << ans << endl;
	return 0;
}
```