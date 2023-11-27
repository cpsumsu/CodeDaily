---
Difficulty: "普及+/提高"
tags: ["枚舉"]
---

> Problem: [P1214 [USACO1.4] 等差数列 Arithmetic Progressions](https://www.luogu.com.cn/problem/P1214)

# 思路
> 枚舉 $k = b + d$ 到 $a + (n - 1) * d$
>
> 然後 $a$ 枚舉到 $250 * 2$
>
> $b$ 也是從 $a$ 到 $250 * 2$

# 复杂度
- 时间复杂度:
> $O(n ^ 2 \text{log} n)$

- 空间复杂度:
> $O(n^2)$
  

# Code
```C++
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
#include <unordered_map>
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

// 用 unordered_map 存儲所有可能 O(n^2)
unordered_map<int, bool> mp;
void initm(int m)
{
	int p, q;
	for (p = 0; p <= m; ++p)
		for (q = 0; q <= m; ++q)
			mp[p * p + q * q] = true;
}

bool isok(int a, int b, int d, int n)
{
	// 這裡改成枚舉 k = b + d
	for (int k = b + d; k <= a + (n - 1) * d; k += d)
		if (!mp[k]) return false;
	return true;
}



int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n, m;
	cin >> n >> m;
	int mx = m * m << 1; // 250^2 * 2
	initm(m);
	vector<vector<int>> ans;
	for (int a = 0; a <= mx; a++)
	{
		if (mp[a])
			for (int b = a+1; b <= mx; b++)
			{
				if (mp[b])
				{
					int dd = b - a;
					if (a + (n - 1) * dd > mx) break;
					if (isok(a, b, dd,n)) 
						ans.push_back({ a,dd });
				}
			}
	}
		
	if (ans.size() == 0) cout << "NONE" << endl;
	else
	{
		sort(ans.begin(), ans.end(), [](auto a, auto b)
			{
				if (a[1] == b[1]) return a[0] < b[0];
				return a[1] < b[1];
			});
		for (auto a : ans)
			cout << a[0] << " " << a[1] << endl;
	}
	return 0;
}
```