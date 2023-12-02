---
Difficulty: "普及+/提高"
tags: ["Dp","Math", "完全背包"]
---

> Problem: [P2737 [USACO4.1] 麦香牛块Beef McNuggets](https://www.luogu.com.cn/problem/P2737)

# 思路
- 題目: 給你 $n$ 個正整數 $a_1, a_2, \cdots, a_n$ ，求出不能用 $p_1a_1 + p_2a_2 + \cdots + p_na_n$ 表示的最大整數。
- 這裡的每一個數都沒有使用限制，所以可以完全背包解決

# 突破口
1. 甚麼時候答案為 $0$ 呢？滿足下式:

$$
gcd(a_1, a_2, \cdots, a_n) = 1
$$

2. 兩個數 $x$ 和 $y$ 不能用 $ax + by$ 表示出來的最大整數為 $xy - x - y$

$$
ax + by = xy - x - y
$$

$$
p(x + 1) + q(y + 1) = pq
$$

$$
gcd(a,b) = 1, p | q(y+1)
$$

$$
p | y+1,\text{ 同理可證 } q | x + 1
$$

3. 因此有:

$$
\sum^n_{i=1}a_ix_i = b, \text{有整數解當且僅當} gcd(a_1, a_2, \cdots, a_n) |b
$$

$$
\text{設: }\text{gcd}(a_1, a_2, \cdots, a_n) = g
$$

$$
g | k_1, g | k_2, \cdots, g | k_n
$$

$$
b = \sum^n_{i=1}a_ix_i
$$

$$
\text{方程解: } g | b
$$


# 复杂度
- 时间复杂度:
> $O(n)$

- 空间复杂度:
> $O(n)$
  
# Code
```C++ 
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
// #include <map>
using namespace std;

typedef long long LL;
typedef long long int lli;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x7f7f7f7f; // 最大值2139062143。用於代替INT_MAX 
const int N = 1e5 + 10; // 用於定義常量數組
#define MAXN ((int) 1e5) //
#define MAXM ((int) 1e5)
#define MAXPROD ((int) 1e5)

int n;
vector<int> A;

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n;
	A.resize(n + 1, 0);
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
		cin >> A[i];
	vector<int> dp(114514 + 1, 0);
	// gcd(a1,a2), lim = a1 * a2 - a1 - a2;
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = A[i]; j <= 114514; ++j)
		{
			dp[j] |= dp[j - A[i]];
		}
	// 找到最大塊數
	for (int i = 114514; i >= 0; --i)
	{
		if (!dp[i])
		{
			ans = i;
			break;
		}
	}
	if (ans > 256 * 256 - 256 - 256)
		ans = 0;
	cout << ans << endl;
	return 0;
}
```