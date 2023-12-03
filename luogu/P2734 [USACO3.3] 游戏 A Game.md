---
Difficulty: "普及+/提高"
tags: ["dp", "前綴和"]
---

> Problem: [P2734 [USACO3.3] 游戏 A Game](https://www.luogu.com.cn/problem/P2734)

# 思路
- DP + 前綴和
- 先手 -> 後手 -> 先手 -> ...
- dp[i][j] 在 [i,j] 中能拿的分數
- dp[1][n] 為先手最大值
- prefix[n] - dp[1][n] 為後手最大值 (後手一定全拿剩下的)

$$
dp[i][j] = max(pre - dp[i+1][j], pre - dp[i][j - 1])
$$

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

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	// dp + 前綴和
	// dp[i][j] 在 [i,j] 中能拿的分數
	// 先手 -> 後手 -> 先手 -> ...
	// dp[i][j] = max(pre - dp[i+1][j], pre - dp[i][j - 1])
	// pre = prefix[j] - prefix[i - 1]
	// dp[1][n] 為先手最大值
	// prefix[n] - dp[1][n] 為後手最大值 (後手一定全拿剩下的)
	vector<int> A(n + 1), prefix(n+1, 0);
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i];
		prefix[i] = prefix[i - 1] + A[i]; //前綴和
		dp[i][i] = A[i]; // 對角元素
	}
	for (int p = 2; p <= n; ++p)
	{
		for (int i = 1; i <= n - p + 1; ++i)
		{
			int j = i + p - 1;
			int pre = prefix[j] - prefix[i - 1];
			dp[i][j] = max(pre - dp[i + 1][j], pre - dp[i][j - 1]);
		}
	}
	cout << dp[1][n] << " " << prefix[n] - dp[1][n];

	return 0;
}
```