---
Difficulty: "普及-"
tags: ["回文數", "n進制"]
---

> Problem: [P1207 [USACO1.2] 双重回文数 Dual Palindromes](https://www.luogu.com.cn/problem/P1207)

# 思路
> 模擬，isok裡是n進制的函數

# 复杂度
- 时间复杂度:
> $O(10^9)$

- 空间复杂度:
> $O(1)$
  

# Code
```C++
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
using namespace std;

typedef long long LL;
typedef long long int lli;
typedef unsigned long long ull;
lli var1, var2;
#define rep(i, l, u) for (lli i = l; i <= u; i++)


template <typename T>
T mmax(const T& lhs, const T& rhs)
{
	return lhs > rhs ? lhs : rhs;
}

template <typename T>
T mmin(const T& lhs, const T& rhs)
{
	return lhs < rhs ? lhs : rhs;
}

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

bool isok(int a, int b)
{
	int as[100] = { 0 };
	int p = 0;
	while (a)
	{
		as[p++] = a % b;
		a /= b;
	}
	int i = 0, j = p - 1;
	while (i < j)
		if (as[i++] != as[j--]) return false;
	return true;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t, s;
	cin >> t >> s;
	for (int i = s + 1; i <= 1e9 && t > 0; ++i)
	{
		//cout << i << ": ";
		int iso = 0;
		for (int j = 2; j <= 10 && iso < 2; ++j)
		{
			if (isok(i,j))
			{
				iso += 1;
				//for (int j = ans; j >= 0; --j) cout << as[j];
				//cout << " ";
			}
		}
		if (iso >= 2)
		{
			cout << i << endl;
			t--;
		}
		//cout << endl;
	}
	return 0;
}
```