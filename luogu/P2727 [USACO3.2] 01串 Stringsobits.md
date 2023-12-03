---
Difficulty: "提高+/省选−"
tags: ["dp"]
---

> Problem: [P2727 [USACO3.2] 01串 Stringsobits](https://www.luogu.com.cn/problem/P2727)

# 思路
> dp: $dp[i][j] =$ 填a個數，然後最多填b個1，的數量

$$
dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
$$

- 如果 L > n, 取對角線(i,i)上的數

```c++
if (j > i)
    dp[i][j] = dp[i][i];
```

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

long long n, l, k;
//int str[50];
//int idx = 0;
//bool dtob(int x)
//{
//	idx = 0;
//	while (x)
//	{
//		str[idx++] = x % 2;
//		x /= 2;
//	}
//	int cnt = 0;
//	for (int j = idx - 1; j >= 0; --j)
//		if (str[idx]) cnt++;
//	return cnt <= l;
//}

// dp
// dp[i][j] = 填a個數，然後最多填b個1，的數量
// dp[i][j] = dp[i-1][j-1] + dp[i-1][j]

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	/*cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);*/
	cin >> n >> l >> k;
	int i = 0;
	vector<vector<long long>> dp(114, vector<long long>(114, 0));
	for (int i = 0; i <= n; ++i) dp[i][0] = 1;
	for (int i = 0; i <= l; ++i) dp[0][i] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= l; ++j)
			// 如果 L > n, 取對角線(i,i)上的數
			if (j > i)
				dp[i][j] = dp[i][i];
			else
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
	// 從後輸出
	for (int i = n; i >= 1; --i)
	{
		if (k && dp[i - 1][l] < k)
		{
			cout << "1";
			k -= dp[i - 1][l];
			l--;
		}
		else
			cout << "0";
	}

	//for (; i < (1 << n) && k >= 0; ++i)
	//{
	//	if (dtob(i)) k--;
	//}
	//for (int j = idx - 1; j >= 0; --j)
	//	cout << str[j];

	return 0;
}
```