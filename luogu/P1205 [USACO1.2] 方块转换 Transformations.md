---
Difficulty: "普及/提高−"
tags: ["模擬"]
---

> Problem: [P1205 [USACO1.2] 方块转换 Transformations](https://www.luogu.com.cn/problem/P1205)

# 思路
> 模擬
> 嘗試 1, 2, 3 方法，180度和270度可由90度方法實現。（看第二個實現）
> 5 方法由 4, 1, 2, 3 方法實現

# 陷阱
> 要是兩個圖形一樣，先不要輸出 6，因為有可能之前的方法能夠實現，而題目要求輸出最小數字

[詳情看題解](https://www.luogu.com.cn/problem/solution/P1205)

# 复杂度
- 时间复杂度:
> $O(n^2)$

- 空间复杂度:
> $O(n^2)$
  

# Code
```cpp
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

vector<vector<char>> r90(vector<vector<char>>& m)
{
	int n = m.size();
	vector<vector<char>> newmap(n, vector<char>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			newmap[j][n-i-1] = m[i][j];
		}
	}
	return newmap;
}
vector<vector<char>> r180(vector<vector<char>>& m)
{
	int n = m.size();
	vector<vector<char>> newmap(n, vector<char>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			newmap[n - i - 1][n - j - 1] = m[i][j];
		}
	}
	return newmap;
}
vector<vector<char>> r270(vector<vector<char>>& m)
{
	int n = m.size();
	vector<vector<char>> newmap(n, vector<char>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			newmap[i][j] = m[j][n - i - 1];
		}
	}
	return newmap;
}
vector<vector<char>> reflect(vector<vector<char>>& m)
{
	int n = m.size();
	vector<vector<char>> newmap(n, vector<char>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			newmap[i][n - j - 1] = m[i][j];
		}
	}
	return newmap;
}
vector<vector<char>> combine(vector<vector<char>>& m,int type)
{
	int n = m.size();
	vector<vector<char>> newmap = reflect(m);
	switch (type)
	{
	case 1:
		return r90(newmap);
		break;
	case 2:
		return r180(newmap);
		break;
	case 3:
		return r270(newmap);
		break;
	}
}

int p(vector<vector<char>> &m1, vector<vector<char>> &m2, int n)
{
	if (r90(m1) == m2)
		return 1;
	else if (r180(m1) == m2)
		return 2;
	else if (r270(m1) == m2)
		return 3;
	else if (reflect(m1) == m2)
		return 4;
	else if (combine(m1, 1) == m2 || combine(m1, 2) == m2 || combine(m1, 3) == m2)
		return 5;
	else if (m1 == m2)
		return 6;
	else
		return 7;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<vector<char>> m1(n, vector<char>(n)), m2(n, vector<char>(n));
		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			for (int j = 0; j < str.size(); ++j)
			{
				m1[i][j] = str[j];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			for (int j = 0; j < n; ++j)
			{
				m2[i][j] = str[j];
			}
		}
		cout << p(m1, m2, n) << endl;
	}
	return 0;
}
```

# second approach

```cpp
#include <bits/stdc++.h>
using namespace std;

template<typename T>
bool is_equal(T &a, T &b) {
    int N = int(a.size());
    for (int i = 0; i < N; i++)
        if (a[i] != b[i])
            return false;

    return true;
}

void run_case() {
    int N;
    cin >> N;

    vector<string> original(N);
    for (auto &x : original)    
        cin >> x;

    vector<string> answer(N);
    for (auto &x : answer)
        cin >> x;

    // init two matrix for rotation
    auto transformed = original;
    auto copy = original;

    // clockwise 90
    auto rotate = [&]() {
        swap(transformed, copy);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                transformed[j][N - i - 1] = copy[i][j];
    };

    // test method 1, 2, 3
    for (int i = 0; i < 3; i++) {
        rotate();

        if (is_equal(transformed, answer)) {
            cout << i + 1 << '\n';
            return ;
        }
    }

    // reflex, method 4
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            transformed[i][N - 1 - j] = original[i][j];

    if (is_equal(transformed, answer)) {
        cout << 4 << '\n';
        return ;
    }

    // method 5, combine with methods 4, 1, 2, 3
    for (int i = 0; i < 3; i++) {
        rotate();
        if (is_equal(transformed, answer)) {
            cout << 5 << '\n';
            return ;
        }
    }

    // method 6
    if (is_equal(original, answer)) {
        cout << 6 << '\n';
        return ;
    }
    
    cout << 7 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    run_case();
    
    return 0;
}   
```
