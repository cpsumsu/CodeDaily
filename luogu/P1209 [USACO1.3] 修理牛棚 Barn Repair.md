---
Difficulty: "普及/提高−"
tags: ["Greedy"]
---

> Problem: [P1209 [USACO1.3] 修理牛棚 Barn Repair](https://www.luogu.com.cn/problem/P1209)

# 思路
> 先排序，然後就可以算牛之間的距離
> 
> 再排序剛剛的距離，一共斷開 m - 1 個距離(從idx大到小)，那就可以取最小的距離了

# 复杂度
- 时间复杂度:
> $O(c * m * \text{log}n)$

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

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int m, s, c;
	cin >> m >> s >> c;
	int cow[255], len[255];
	for (int i = 1; i <= c; ++i)
	{
		cin >> cow[i];
	}
	if (m >= c)
	{
		printf("%d\n", c);
		return 0;
	}
	sort(cow + 1, cow + c + 1); // 小到大
	for (int i = 1; i <= c; ++i)
	{
		len[i] = cow[i + 1] - cow[i] - 1; // 牛之間的距離
	}
	sort(len + 1, len + c, [](auto a, auto b) {return a > b; });
	int ans = cow[c] - cow[1] + 1;
	for (int i = 1; i <= m - 1; ++i) 
		ans -= len[i]; // 一共斷開 m - 1 個距離(從idx大到小
	printf("%d\n", ans);
	return 0;
}


```