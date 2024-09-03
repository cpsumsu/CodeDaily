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

要是看不懂上述的題解沒關係，我也看不懂。。。
還是我這個比較清楚 :)

```cpp
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

unordered_set<int> A;

// check if the number of digits `x` equals to `num` 
bool check_digits(int x, int num) {
    while (x) {
        x /= 10;
        num--;
    }

    return num != 0 ? false : true;
}

// check if we can find the characters of x in set
bool number_contains(int x) {
    while (x) {
        if (A.find(x % 10) == A.end())
            return false;

        x /= 10;
    }

    return true;
}

bool check(int x, int y) {
    if (!number_contains(x) || !number_contains(y))		// check if x and y are suitable 
        return false;

    int first_digit = y % 10;
    y /= 10;
    int second_digit = y;

    int r1 = first_digit * x;
    int r2 = second_digit * x;

    if (!check_digits(r1, 3) || !check_digits(r2, 3))		// check if they are 3 digits 
        return false;

    int r3 = r1 + r2 * 10;
    if (!check_digits(r3, 4))			// check if the final result is 4 digits
        return false;

    return number_contains(r1) && number_contains(r2) && number_contains(r3);
}

void run_case() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A.insert(x);
    }

    int sol = 0;

    for (int i = 100; i <= 999; i++) {
        for (int j = 10; j <= 99; j++) {
            if (check(i, j)) {
                // cout << i << ' ' << j << '\n';
                sol++;
            }
        }
    }    

    cout << sol << '\n';
}

int main() {
    fastio
    
    run_case();
    
    return 0;
}
```