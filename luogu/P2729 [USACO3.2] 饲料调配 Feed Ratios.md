---
Difficulty: "普及/提高−"
tags: ["枚舉"]
---

> Problem: [P2729 [USACO3.2] 饲料调配 Feed Ratios](https://www.luogu.com.cn/problem/P2729)

# 思路
> 暴力。四層循環

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
	vector<vector<int>> dp(3, vector<int>(3, 0));
	int x, y, z;
	cin >> x >> y >> z;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; ++j)
			cin >> dp[i][j];
	int ai, aj, ak, aa;
	int mmin = INF;
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			for (int k = 0; k < 100; ++k)
				for (int a = 1; a < 100; ++a)
				{
					if (i * dp[0][0] +
						j * dp[1][0] +
						k * dp[2][0] !=
						a * x) continue;
					if (i * dp[0][1] +
						j * dp[1][1] +
						k * dp[2][1] !=
						a * y) continue;
					if (i * dp[0][2] +
						j * dp[1][2] +
						k * dp[2][2] !=
						a * z) continue;
					if (i + j + k < mmin)
					{
						mmin = min(mmin, i + j + k);
						ai = i, aj = j, ak = k, aa = a;
					}
				}
	if (mmin != INF)
		printf("%d %d %d %d", ai, aj, ak, aa);
	else
		printf("NONE");
	return 0;
}
```