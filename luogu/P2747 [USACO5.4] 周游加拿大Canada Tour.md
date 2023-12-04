---
Difficulty: "提高+/省选−"
tags: ["String", "dp"]
---

> Problem: [P2747 [USACO5.4] 周游加拿大Canada Tour](https://www.luogu.com.cn/problem/P2747)

# 思路
- 最短路dp

- 使用動態規劃算法。
- 兩條路徑：$1$ 到 $n$，然後 $n$ 到 $1$ （總共 $n$ 個城市）。
- 我們可以認為兩條路徑都從城市 $1$ 開始：( $1$ 到 $i$ ) 和 ( $1$ 到 $j$ )，除了城市 $1$ 之外的所有城市只能訪問一次。

答案是這兩條路徑所造訪過的城市總數，定義為 $f[i][j]$ 。

由於這兩條路徑的條件相同，因此我們只需計算 $i < j$ 的條件即可，並且在 $j < i$ 的條件下將有相同的解。 $f[i][j] = f[j][i]$

- 我們也定義了一個城市 $k$ ，它是到達 $j$ 之前最後到達的城市。 (k < j) 由於所有城市只能造訪一次，因此 $f[i][j]$ 的答案可以轉移到 $f[i][k] + 1$ 。

$f[i][j] = f[i][k] + 1$（當 $f[i][k]$ 有成功解時）

因此，我們可以建構DP算法：
- 初始狀態： $f[1][1] = 1$ ，其他 $f[x][y] = -1$
- 狀態轉移方程式：$f[i][j] = f[i][k] + 1$ ，則 $f[j][i] = f[i][j]$

# 复杂度
- 时间复杂度:
> $O(N^3)$

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
const int N = 1e5 + 10; // 用於定義常量數組
#define MAXN ((int) 1e5) //
#define MAXM ((int) 1e5)
#define MAXPROD ((int) 1e5)

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n, v;
	cin >> n >> v;
	string c1, c2;
	int n1, n2;
	vector<vector<int>> edges(114, vector<int>(114, 0));
	unordered_map<string, int> mp;
	for (int i = 0; i < n; ++i)
	{
		cin >> c1;
		mp[c1] = i;
	}
	for (int i = 0; i < v; ++i)
	{
		cin >> c1 >> c2;
		n1 = mp[c1], n2 = mp[c2];
		edges[n1][n2] = 1;
		edges[n2][n1] = 1;
	}
	vector<vector<int>> dp(114, vector<int>(114, -514));
	dp[0][0] = 1;
	// 最短路
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			for (int k = 0; k < j; ++k)
			{
				if (edges[j][k])
				{
					dp[i][j] = max(dp[i][j], dp[i][k] + 1);
					dp[j][i] = dp[i][j];
				}
			}
	int ans = 1;
	for (int i = 0; i < n; ++i)
		if (edges[i][n-1]) ans = max(ans, dp[i][n - 1]);
	cout << ans << endl;
	return 0;
}
```