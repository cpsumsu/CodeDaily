---
Difficulty: "普及/提高−"
tags: ["構造"]
---

> Problem: [P1134 [USACO3.2] 阶乘问题](https://www.luogu.com.cn/problem/P1134)

# 思路
> 原本是想找規律的，但是暴力模擬就過了

# Code
```c++
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

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t; // 測試用例
	cin >> t;
	long long cur = 1;
	// 11264224288
	// 86828868244
	// 846448468....
	// 只有 2 4 6 8 除了1 ~ 9
	// 6828 6824 8468 ??
	for (int i = 1; i <= t; ++i)
	{
		cur *= i;
		while (cur % 10 == 0)
			cur /= 10;
		cur %= 100000000;
	}
	cout << cur % 10 << endl;
	return 0;
}
```