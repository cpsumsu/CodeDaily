---
Difficulty: "普及−"
tags: ["枚舉"]
---

> Problem: [P1211 [USACO1.3] 牛式 Prime Cryptarithm](https://www.luogu.com.cn/problem/P1211)

# 思路
> 枚舉

# 复杂度
- 时间复杂度:
> $O(999 * 99)$

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

bool isok(int x,bool s[])
{
	while (x)
	{
		int t = x % 10;
		if (!s[t]) return false;
		x /= 10;
	}
	return true;
}

void p(bool s[])
{
	int ans = 0;
	for (int i = 100; i < 999; ++i)
	{
		if (isok(i, s))
			for (int j = 10; j < 99; ++j)
			{
				if (isok(j, s))
				{
					int ti = j / 10; // 10
					int fi = j % 10; // 0
					if (fi * i > 999 || ti * i > 999 || i * j > 9999) continue;
					else if (isok(fi * i, s) && isok(ti * i, s) && isok(i * j, s))
						ans += 1;
				}
			}
	}
	cout << ans << endl;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	bool s[10] = { 0 };
	for (int i = 0; i < t; ++i)
	{
		int tmp; cin >> tmp;
		s[tmp] = true;
	}
	p(s);
	return 0;
}


```