---
Difficulty: "普及+/提高"
tags: ["dp", "dfs"]
---

> Problem: [P2736 [USACO3.4] “破锣摇滚”乐队 Raucous Rockers](https://www.luogu.com.cn/problem/P2736)

# 思路
- dp背包問題，下方Code提供了從DFS到DP優化的完整思路過程，如果只用DFS而且不加上哈希表的話一定會TLE的。建議每想好DFS之後就改用DP，而且DP的程式碼會比較簡潔。

# 背包 DFS 思考
- 如果超過背包容量，只能不放入 ...
- 如果不超過背包容量，就放入 ...

```c++
// 容量T，有M張CD
// 不選: dp[i-1][j][cd]
// 選: dp[i-1][j - CD[i]][cd] (減容量)
// 轉CD: dp[i-1][t - CD[i]][cd-1] (減CD數量)
// dp[i][j] = max(dp[i-1][j],
```

# Dp
- 能不能把三維dp壓成二維？ (可以，只需要合併 t 和 m 維)

$$
dp[i][w] = max(dp[i][w], dp[i - 1][w - CD[i]] + 1);
$$

$$
dp[i][w] = max(dp[i][w], dp[i - 1][w / t * t - CD[i]] + 1);
$$

```c++
// 如果超過背包容量，默認不放入
			dp[i][w] = dp[i-1][w];
			if (CD[i] <= w % t)
			{
				dp[i][w] = max(dp[i][w], dp[i - 1][w - CD[i]] + 1);
			}
			else if (CD[i] <= w / t * t)
			{
				dp[i][w] = max(dp[i][w], dp[i - 1][w / t * t - CD[i]] + 1);
			}
```

# 复杂度
- 时间复杂度:
> $O(ntm)$

- 空间复杂度:
> $O(ntm)$
  
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
const int N = 1e5 + 10; // 用於定義常量數組
#define MAXN ((int) 1e5) //
#define MAXM ((int) 1e5)
#define MAXPROD ((int) 1e5)

int moves[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }; // 4向移動 順時針
// int moves[8][2] = { {0,1},{1,0},{-1,0},{0,-1}, {1,1},{-1,1},{1,-1},{-1,-1} }; // 8向移動
// int moves[6][2] = { {0,1},{1,0},{1,-1},{0,-1},{-1,0},{-1,1} }; // 六邊移動 (網格六邊形專用)

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
int n, t, m;
vector<int> CD;
vector<vector<vector<int>>> mem;

// dp 背包問題
// 容量T，有M張CD
// 不選: dp[i-1][j][cd]
// 選: dp[i-1][j - CD[i]][cd] (減容量)
// 轉CD: dp[i-1][t - CD[i]][cd-1] (減CD數量)
// dp[i][j] = max(dp[i-1][j],

// dfs
int dfs(int ln, int lt, int lm)
{
	if (ln == 0 || lt == 0) return 0;
	if (mem[ln][lt][lm] != -1)
		return mem[ln][lt][lm];
	// 如果超過背包容量，只能不放入
	if (CD[ln - 1] > lt)
	{
		if (CD[ln - 1] <= t && lm != 0)
			return dfs(ln - 1, t - CD[ln - 1], lm - 1) + 1;
		return dfs(ln - 1, lt, lm);
	}
	int no = dfs(ln - 1, lt, lm);
	int yes = dfs(ln - 1, lt - CD[ln - 1], lm) + 1;
	mem[ln][lt][lm] = max(no,yes);
	return max(no, yes);
}

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n >> t >> m;
	CD.resize(114, 0);
	// mem.resize(n + 1, vector<vector<int>>(t + 1, vector<int>(m + 1, -1)));
	for (int i = 1; i <= n; ++i)
		cin >> CD[i];
	/*int ans = dfs(n, t, m);
	cout << ans << endl;*/

	// 合併 t 和 m 維
	vector<vector<int>> dp(n + 20, vector<int>(t * m + 114, 0));
	// 邊界條件
	for (int i = 1; i <= n; ++i)
		for (int w = 1; w <= t * m; ++w)
		{
			// 如果超過背包容量，默認不放入
			dp[i][w] = dp[i-1][w];
			if (CD[i] <= w % t)
			{
				dp[i][w] = max(dp[i][w], dp[i - 1][w - CD[i]] + 1);
			}
			else if (CD[i] <= w / t * t)
			{
				dp[i][w] = max(dp[i][w], dp[i - 1][w / t * t - CD[i]] + 1);
			}
		}
	cout << dp[n][t * m] << endl;

	return 0;
}
```