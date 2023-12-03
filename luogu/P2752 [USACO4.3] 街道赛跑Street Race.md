---
Difficulty: "提高+/省选−"
tags: ["DFS"]
---

> Problem: [P2752 [USACO4.3] 街道赛跑Street Race](https://www.luogu.com.cn/problem/P2752)

# 思路
- 先找不可避免的路口，再從不可避免的路口找中間路口
- 嘗試從起點 $0$ 開始走一遍路線，以了解可以訪問哪些點。如果無法存取終點 $N$ ，則該點為不可避免的路口。
- 以同一點i為起點，試著從該點開始走一遍路線，以了解可以訪問哪些點。
所有這些訪問過的點都可以被認為是右分割部分。 （因為從中間點i開始，命名為vis2[]）
- 然後遍歷所有點並檢查 $vis1[]$ 和 $vis2[]$ 中的狀態。
- 如果有一個點在 $vis1[]$ 和 $vis2[]$ 中都被訪問過，則表示該點在路線的左右部分之間有中間路口。如果有公共點，則不是中間路口

# 复杂度
- 时间复杂度:
> $O(nm_2)$

- 空间复杂度:
> $O(n + m)$
  
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

vector<vector<int>> map;
int vis[1145], vis2[1145];
int n = 0;
void dfs(int x)
{
	for (int i = 0; i < map[x].size(); ++i)
	{
		int cur = map[x][i];
		if (!vis[cur])
		{
			vis[cur] = 1;
			dfs(cur);
		}
	}
}
void dfs2(int x)
{
	for (int i = 0; i < map[x].size(); ++i)
	{
		int cur = map[x][i];
		if (!vis2[cur])
		{
			vis2[cur] = 1;
			dfs2(cur);
		}
	}
}

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	map.resize(105);
	while (cin >> t && t != -1)
	{
		if (t == -2) n++;
		else
		{
			map[n].push_back(t);
		}
	}
	n--;
	vector<int> ans1, ans2;
	for (int i = 0; i < n; ++i)
	{
		memset(vis, 0, sizeof(vis));
		vis[0] = 1;
		vis[i] = 1;
		dfs(0); // 標記起點能去的點
		if (!vis[n]) // 這是不可避免的路口
		{
			// 不可避免的路口找中間路口
			ans1.push_back(i);
			memset(vis2, 0, sizeof(vis2));
			vis2[i] = 1;
			dfs2(i); // 找從點i去到的點
			bool fg = true;
			for (int j = 0; j <= n; ++j)
			{
				// 如果有公共點，則不是中間路口
				if (vis[j] && vis2[j] && j != i)
				{
					fg = false;
					break;
				}
			}
			if (fg) ans2.push_back(i);
		}
	}
	sort(ans1.begin(), ans1.end());
	sort(ans2.begin(), ans2.end());
	cout << ans1.size() << " ";
	if (ans1.size() != 0)
	{
		for (int i = 0; i < ans1.size() - 1; ++i)
			cout << ans1[i] << " ";
		cout << ans1[ans1.size() - 1] << endl;
	}
	else cout << endl;
	cout << ans2.size() << " ";
	if (ans2.size() != 0)
	{
		for (int i = 0; i < ans2.size() - 1; ++i)
			cout << ans2[i] << " ";
		cout << ans2[ans2.size() - 1] << endl;
	}
	return 0;
}
```