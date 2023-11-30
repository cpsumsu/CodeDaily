---
Difficulty: "提高+/省选−"
tags: ["枚舉","BFS"]
---

> Problem: [P2749 [USACO5.1] 夜空繁星Starry Night](https://www.luogu.com.cn/problem/P2749)

# 思路
- 枚舉甚麼？怎麼知道哪些是相似的星星？
- 其實在這個題目中，兩個相似星星，他們與所有星星之間的距離幾乎相同，所以我們只需要枚舉星星之間的距離，就可以得到答案了。
- 接下來怎麼算距離，就用BFS

$$
\text{相似星星} = \sum_{i = 1}^{n} \sum_{j = 1, j \neq i}^{n} \text{distance}(i, j)
$$

# BFS
- 使用 BFS來枚舉，對於每個點，我們都找所有鄰接點，將其距離加一。如果是星星，就將星星點加入queue中
- 注意到每次算到不同的 $Distance$ 值時，我們都要將 $total$ 加一，因為我們要算的是不同距離的星星數量。

# 更新地圖星星的英文字母方法

```c++
for (int i = 1; i <= t; ++i)
    mp[stars[i].first][stars[i].second] = 'a' + total - 1;
```

# 复杂度
- 时间复杂度:
> $O(nm * \frac{n}{2})$

- 空间复杂度:
> $O(1)$
  
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
#include <cmath>
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

// int moves[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }; // 4向移動 順時針
// int moves[6][2] = { {0,1},{1,0},{1,-1},{0,-1},{-1,0},{-1,1} }; // 六邊移動 (網格六邊形專用)
int cnt = 0;
int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int m, n;
	cin >> m >> n;
	int moves[8][2] = { {0,1},{1,0},{-1,0},{0,-1}, {1,1},{-1,1},{1,-1},{-1,-1} }; // 8向移動
	vector<string> mp;
	vector<vector<int>> vis(114, vector<int>(114, 0));
	queue<PII> q;
	vector<PII> stars(114514);
	vector<double> dis(114514);
	int total = 0;
	for (int i = 0; i < n; ++i)
	{
		string tmp;
		cin >> tmp;
		mp.push_back(tmp);
	}
	// cout << "ok" << endl;
	auto distance = [&](const PII& A, const PII& B) -> double
		{
			return sqrt(
				(A.first - B.first) * (A.first - B.first) +
				(A.second - B.second) * (A.second - B.second));
		};
	auto cok = [&](const int& t) ->void
		{
			double d = 0;
			int idx = 0;
			for (int i = 1; i < t; ++i)
				for (int j = i + 1; j <= t; ++j)
				{
					// 算星星之間的距離
					d += distance(stars[i], stars[j]); 
				}
			for (int i = 1; i <= total; ++i)
				if (fabs(d - dis[i]) <= 0.000001)
				{
					idx = i;
					break;
				}
			if (!idx) // 新星星
			{
				total++;
				dis[total] = d;
				for (int i = 1; i <= t; ++i)
					mp[stars[i].first][stars[i].second] = 'a' + total - 1;
			}
			else // 相似星星
			{
				for (int i = 1; i <= t; ++i)
					mp[stars[i].first][stars[i].second] = 'a' + idx - 1;
			}
		};
	auto bfs = [&](const int& i, const int& j) -> void 
		{
			vis[i][j] = 1;
			int t = 1;
			stars[t] = { i,j };
			q.push({ i,j });
			while (!q.empty())
			{
				PII cur = q.front(); q.pop();
				for (auto v : moves)
				{
					int x = cur.first + v[0], y = cur.second + v[1];
					// cout << x << " " << y << endl;
					if (x >= 0 && x < n && y >= 0 && y < m && mp[x][y] == '1' && !vis[x][y])
					{
						t++;
						stars[t] = { x,y };
						vis[x][y] = true;
						q.push({ x,y });
					}
				}
			}
			cok(t);
		};
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			// cout << i << ' ' << j << endl;
			if (mp[i][j] == '1' && !vis[i][j])
				bfs(i, j);
		}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cout << mp[i][j];
		cout << endl;
	}
	return 0;
}
```