---
Difficulty: "普及+/提高"
tags: ["dp", "dfs"]
---

> Problem: [P2687 [USACO4.3] 逢低吸纳Buy Low, Buy Lower](https://www.luogu.com.cn/problem/P2687)

# 思路
- DP，不過這一題的最後一項測試數據超級大(輸入數據大約有5000位數字)，所以這裡另外使用 $solve$ 函數和 $dp$ 數組去處理

$$
dp[i] = max(dp[i], dp[j] + 1)
$$

# Dp


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

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

// 檢查是否是質數
bool isprime(int x)
{
	if (x < 2) return false;
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0) return false;
	return true;
}

// 檢查是否是回文數、回文串
bool ok(int i)
{
	string s = to_string(i);
	int n = s.size();
	for (int i = 0; i < n; ++i)
		if (s[i] != s[n - 1 - i]) return false;
	return true;
}

int n;
// A 為數字，B 為長度，tmp用於存放其他方案數
vector<int> A, B;
vector<int> tmp;
// dp
vector<vector<int>> dp;

void solve(int a, int b)
{
	int k = 0, len = max(tmp[a], tmp[b]);
	for (int i = 1; i <= len; ++i)
	{
		if (tmp[a] < i) dp[i][a] = 0;
		if (tmp[b] < i) dp[i][b] = 0;
		dp[i][a] += dp[i][b] + k;
		k = dp[i][a] / 10;
		dp[i][a] %= 10;
	}
	if (k != 0) dp[++len][a] = k; // 進位
	tmp[a] = len; // 數字長度
}

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n;
	A.resize(5005), B.resize(5005), tmp.resize(5005);
	dp.resize(1005, vector<int>(5005));
	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i];
		B[i] = 1;
	}
	int ansu = 0, ansv = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			// // 轉移 bi = max(bi, bj + 1)
			if (A[i] < A[j]) B[i] = max(B[i], B[j] + 1);
		}
		for (int j = 1; j < i; ++j)
		{
			// 不用tmp，用dp做
			if (A[i] < A[j] && B[i] == B[j] + 1) solve(i, j);
			else if (A[i] == A[j] && B[i] == B[j]) tmp[j] = 0;
		}
		// tmp[i] = max(tmp[i], 1);
		ansu = max(ansu, B[i]);
		if ((tmp[i] == 0 || tmp[i] == 1) && dp[1][i] < 1)
			dp[1][i] = 1, tmp[i] = 1;
	}
	cout << ansu << " "; // 子序列長度
	for (int i = 1; i <= n; ++i)
		if (B[i] == ansu) solve(5003, i);
	for (int i = tmp[5003]; i; i--)
		cout << dp[i][5003]; // 倒後輸出
	return 0;
}
```