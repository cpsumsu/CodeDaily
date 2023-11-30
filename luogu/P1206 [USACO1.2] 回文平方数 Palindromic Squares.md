---
Difficulty: "普及-"
tags: ["回文數", "n進制"]
---

> Problem: [P1206 [USACO1.2] 回文平方数 Palindromic Squares](https://www.luogu.com.cn/problem/P1206)

# 思路
> 使用數組去模擬進制進位，最後返回當前數組最後一個下標

# 复杂度
- 时间复杂度:
> $O(300 * 300)$

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

char s[1000];
int bbb(int k,int B)
{
	int p = -1, j;
	int x = k;
	while (x)
	{
		j = x % B;
		x /= B;
		if (j >= 10)
			s[++p] = 'A' + j - 10;
		else
			s[++p] = j + '0';
	}
	s[++p] = 0;
	return p - 1;
}
char as[1000];
int abb(int k, int B)
{
	int p = -1, j;
	int x = k;
	while (x)
	{
		j = x % B;
		x /= B;
		if (j >= 10)
			as[++p] = 'A' + j - 10;
		else
			as[++p] = j + '0';
	}
	as[++p] = 0;
	return p - 1;
}


bool isok(int k)
{
	int i;
	for (i = 0; i <= (k - 1) / 2; ++i)
		if (as[i] != as[k - i]) break;
	if (i > (k - 1) / 2) return true;
	return false;
}

int main()
{
	int B;
	cin >> B;
	if (B >= 'A') B = (B - 'A') + 10;
	cout << "1 1" << endl;
	for (int i = 2; i <= 300; ++i)
	{
		int ans = abb(i * i, B);
		if (isok(ans))
		{
			int pre = bbb(i, B);
			for (int j = pre; j >= 0; j--) cout << s[j];
			cout << " ";
			for (int j = ans; j >= 0; --j) cout << as[j];
			cout << "\n";
		}
	}
	return 0;
}
```