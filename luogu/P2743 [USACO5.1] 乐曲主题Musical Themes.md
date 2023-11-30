---
Difficulty: "提高+/省选−"
tags: ["dp"]
---

> Problem: [P2743 [USACO5.1] 乐曲主题Musical Themes](https://www.luogu.com.cn/problem/P2743)

# 思路
- dp

# 這也能dp啊?
- $dp[i][j] = min(j - i - 1, dp[i - 1][j - 1] + 1);$
- j 直接從 $i + ans + 1$ 開始找

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
const int N = 1e5 + 10; // 用於定義常量數組
#define MAXN ((int) 1e5) //
#define MAXM ((int) 1e5)
#define MAXPROD ((int) 1e5)

int moves[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }; // 4向移動 順時針
// int moves[8][2] = { {0,1},{1,0},{-1,0},{0,-1}, {1,1},{-1,1},{1,-1},{-1,-1} }; // 8向移動
// int moves[6][2] = { {0,1},{1,0},{1,-1},{0,-1},{-1,0},{-1,1} }; // 六邊移動 (網格六邊形專用)

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n, ans = 0;
	cin >> n;
	vector<int> A(n,0), d(n,0);
	vector<vector<int>> dp(n, vector<int>(n,0));
	cin >> A[0];
	for (int i = 1; i < n; ++i)
	{
		cin >> A[i];
		d[i] = A[i] - A[i - 1];
	}
	for (int i = 1; i < n; ++i)
		for (int j = i + ans + 1; j < n; ++j)
			if (d[i] == d[j])
			{
				dp[i][j] = min(j - i - 1, dp[i - 1][j - 1] + 1);
				ans = max(ans, dp[i][j]);
			}
	if (ans > 3) ans++;
	else ans = 0;
	cout << ans << endl;
	return 0;
}
```