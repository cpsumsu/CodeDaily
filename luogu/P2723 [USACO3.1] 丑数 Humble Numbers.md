---
Difficulty: "普及/提高−"
tags: ["dp"]
---

> Problem: [P2723 [USACO3.1] 丑数 Humble Numbers](https://www.luogu.com.cn/problem/P2723)

# 思路
- 為了找第 $i$ 個醜數，那麼一定要比第 $i-1$ 個醜數大，而且是最小的那一個，可以發現比 $i-1$ 大的醜數一定是比 $i-1$ 小的醜數乘 某個質數得到的，鑑於質數的數量很少，而醜數的數量很大，我們枚舉質數，然後枚舉醜數，直到大於第 $i-1$ 個醜數，記錄一下，找到所有的符合條件的醜數以後，找出最小值（也可以在尋找的途中更新最小值），那麼這個最小值就是第 $i$ 個醜數。
- answer from luogo

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

int dp[N];

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int k, n;
	dp[0] = 1;
	cin >> k >> n;
	vector<int> s(k + 1), vis(k + 1);
	unordered_map<int, bool> mp;
	for (int i = 1; i <= k; ++i)
	{
		cin >> s[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		int res = INF;
		for (int j = 1; j <= k; ++j)
		{
			auto& bb = vis[j];
			while (dp[bb] * s[j] <= dp[i - 1]) bb++;
			res = min(res, dp[bb] * s[j]);
		}
		dp[i] = res;
	}
	cout << dp[n] << endl;
	return 0;
}
```