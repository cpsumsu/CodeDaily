---
Difficulty: "提高+/省选−"
tags: ["Greedy", "枚舉"]
---

> Problem: [P2751 [USACO4.2] 工序安排 Job Processing](https://www.luogu.com.cn/problem/P2751)

# 思路

```
机器在一次操作中干掉一个工件；
时间总和的意思是最晚时间点。
```

- 那麼我們每次增加一個機器的可使用時間
- 當一個機器的可使用時間等於單次操作時間就可以工作
- $moveA[0]$ 和 $moveB[0]$ 表示當前機器的使用完的最晚时间点
- 答案取 $A$ 中最小和 $B$ 中最大取配值

$$
ans = max(ans, moveA[i] + moveB[n - i + 1])
$$

# 复杂度
- 时间复杂度:
> $O(nm_2)$

- 空间复杂度:
> $O(n + m)$
  
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

int A[1145], B[1145];
int cntA[1145], cntB[1145];
int moveA[1145], moveB[1145];

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	for (int i = 1; i <= m1; ++i) cin >> A[i];
	for (int i = 1; i <= m2; ++i) cin >> B[i];

	int cnt = n, k = 0;
	// k 為時間
	while (cnt)
	{
		k++;
		for (int i = 1; i <= m1; ++i)
		{
			cntA[i]++;
			// 當一個機器的可使用時間等於單次操作時間
			// 做!
			if (A[i] == cntA[i])
				cntA[i] = 0, moveA[cnt--] = k;
			if (!cnt) break;
		}
	}
	cout << k << " ";
	cnt = n, k = 0;
	// b機也一樣
	while (cnt)
	{
		k++;
		for (int i = 1; i <= m2; ++i)
		{
			cntB[i]++;
			if (B[i] == cntB[i])
				cntB[i] = 0, moveB[cnt--] = k;
			if (!cnt) break;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans = max(ans, moveA[i] + moveB[n - i + 1]);
	}
	cout << ans << endl;
	return 0;
}
```