---
Difficulty: "普及/提高−"
tags: ["幾何"]
---

> Problem: [P2735 [USACO3.4] 网 Electric Fences](https://www.luogu.com.cn/problem/P2735)

# 思路
- 觀察以下正方形，裡面都有個小正方形，小正方形的邊長為$1$

```c++
*******************
*     *     *     *
*  $  *  $  *  $  *
*     *     *     *
*******************
*     *     *     *
*  $  *  $  *  $  *
*     *     *     *
*******************
*     *     *     *
*  $  *  $  *  $  *
*     *     *     *
*******************
```

- 畫個對角線: 把 $\$$ 點 給分開左右兩邊

```c++
******************+
*     *     *    +*
*  $  *  $  *  $  *
*     *     *+    *
************+******
*     *    +*     *
*  $  *  $  *  $  *
*     *+    *     *
******+************
*    +*     *     *
*  $  *  $  *  $  *
*+    *     *     *
+******************
```

- 這樣左右兩點各獲得 4.5個 $\$$ 點，因此有以下公式: (皮克定理)

$$
A = i + \frac{b}{2} - 1
$$


# 复杂度
- 时间复杂度:
> $O(n^2)$

- 空间复杂度:
> $O(n^2)$
  
# Code optimized
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

// (0,0) -> (n,m) -> (p,0)
int n, m, p;
//bool f(double x)
//{
//	return x - (double)(int)x == 0.5;
//}

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n >> m >> p;
	// 皮克定理
	//int cnt1 = 0, cnt2 = 0, ans = 0;
	//for (double i = 0.5; i <= n; i += 0.5)
	//{
	//	double j = i * m / n;
	//	if (f(j)) cnt1++;
	//}
	//if (n != p)
	//{
	//	double st, ed;
	//	if (n > p) st = p, ed = n;
	//	else st = n, ed = p;
	//	for (double i = st + 0.5; i <= ed; i += 0.5)
	//	{
	//		double j = ((i - p) / (n - p)) * m;
	//		if (f(j)) cnt2++;
	//	}
	//	if (n > p) ans -= ((ed - st) * m - cnt2) / 2;
	//	else ans += ((ed - st) * m - cnt2) / 2;
	//}
	//ans += (m * n - cnt1) / 2;
	//cout << ans << endl;
	// 原來可以用gcd直接做
	int s = (p * m) / 2;
	// (0,0)到(n,m)中: 有 gcd(n,m) + 1 個點
	// 如果 x 整除 n 和 m，(x/n,x/m) 符合條件
	// 把三邊算出來
	int tmp = (gcd(n, m) + gcd(abs(n - p), m) + p) / 2;
	cout << s - tmp + 1 << endl;
	return 0;
}
```