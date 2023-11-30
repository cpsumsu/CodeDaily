---
Difficulty: "普及-"
tags: ["Greedy"]
---

> Problem: [P1208 [USACO1.3] 混合牛奶 Mixing Milk](https://www.luogu.com.cn/problem/P1208)

# 思路
> 先排序，貪心選最小單價，其次最多牛奶量
>
> 買完 $n$ 量牛奶就完了

# 复杂度
- 时间复杂度:
> $O(n\text{log}n)$

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

void p(vector<vector<int>> fam,int n)
{
	sort(fam.begin(), fam.end(), [](auto a, auto b)
	{
		if (a[0] == b[0]) return b[1] > a[1];
		return a[0] < b[0];
	});
	//cout << endl;
	//for (auto a : fam) cout << a[0] << " " << a[1] << endl;
	int ii = 0, ans = 0;
	while (n)
	{
		if (n - fam[ii][1] < 0)
		{
			ans += n * fam[ii][0];
			break;
		}
		else
		{
			int tmp = fam[ii][1] * fam[ii][0];
			ans += tmp;
			n -= fam[ii][1];
		}
		ii++;
	}
	cout << ans << endl;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t, k;
	cin >> t >> k;
	vector<vector<int>> fam(k, vector<int>(2));
	for (int i = 0; i < k; ++i)
	{
		cin >> fam[i][0] >> fam[i][1];
	}
	p(fam, t);
	return 0;
}
```