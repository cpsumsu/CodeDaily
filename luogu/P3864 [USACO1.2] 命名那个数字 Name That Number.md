---
Difficulty: "普及/提高−"
tags: ["模擬"]
---

> Problem: [P3864 [USACO1.2] 命名那个数字 Name That Number](https://www.luogu.com.cn/problem/P3864)

# 思路
> 模擬
> 0 技巧，每個都試一下
> 難點在於如何從數字轉換字母

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
#include <sstream>
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

// 222 333 444 555 666 7 77 888 999
// ABC DEF GHI JKL MNO PQRS TUV WXY
const string AtoZ = "2223334445556667 77888999";

bool cmp(string &name, string &number)
{
	int n = number.size();
	for (int j = 0; j < n; ++j)
	{
		if (AtoZ[name[j] - 'A'] != number[j])
		{
			return false;
		}
	}
	return true;
}

void p(vector<string> &names, string &number)
{
	int n = names.size(), m = number.size();
	bool NoAns = true;
	for (int i = 0; i < n; ++i)
	{
		if (names[i].size() != m) continue;
		else if (cmp(names[i], number))
		{
			cout << names[i] << endl;
			NoAns = false;
		}
	}
	if (NoAns)
	{
		cout << "NONE" << endl;
	}
}

int main()
{
	string n;
	cin >> n;
	string tmp;
	vector<string> name;
	while (cin >> tmp)
	{
		name.push_back(tmp);
	}
	p(name, n);
	return 0;
}
```