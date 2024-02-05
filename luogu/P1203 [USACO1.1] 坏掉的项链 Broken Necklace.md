---
Difficulty: "普及−"
tags: ["三指針"]
---

> Problem: [P1203 [USACO1.1] 坏掉的项链 Broken Necklace](https://www.luogu.com.cn/problem/P1203)

# 思路
> 模擬，三指針

# 复杂度
- 时间复杂度:
> $O(n)$

- 空间复杂度:
> $O(1)$
  

# Code
```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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


int ncs(int n, string str)
{
	int ans = 0;
	if (str.size() == 1 || str.size() == 2) return str.size();
	string s = str + str;
	bool only1and2 = true;
	char ch1 = ' ', ch2 = ' ';
	int w = 0, j = 0, k = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'w')
		{
			w++;
			j++;
		}
		else if (s[i] == ch1)
		{
			w = 0;
			j++;
		}
		else
		{
			ch1 = s[i];
			ans = max(ans, k + j);
			k = j - w;
			j = w + 1;
			w = 0;
		}
	}
	ans = max(ans, k + j); // 計算最後的j
	return min(ans,n); // 不超過當前長度
}

int main()
{
	int i;
	string str;
	while (std::cin >> i >> str)
	{
		printf("%d\n", ncs(i, str));
	}
	return 0;
}
```