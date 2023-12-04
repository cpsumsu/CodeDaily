---
Difficulty: "普及/提高−"
tags: ["dp"]
---

> Problem: [P2701 [USACO5.3] 巨大的牛棚Big Barn](https://www.luogu.com.cn/problem/P2701)

# 思路
- 檢查與周遭三格方塊數字是否相同即可

# Dp

```c++
if (mp[i][j] == mp[i + 1][j + 1] &&
    mp[i][j] == mp[i + 1][j] &&
	mp[i][j] == mp[i][j + 1])
```

# 复杂度
- 时间复杂度:
> $O(n(n-k)^2)$

- 空间复杂度:
> $O(n^2)$
  
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

int mp[1010][1010];

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n, t; // 測試用例
	cin >> n >> t;
	for (int i = 0; i < t; ++i)
	{
		int x, y;
		cin >> x >> y;
		mp[x-1][y-1] = -1;
	}
	int ans = 0;
	for (int k = 1; k <= n; ++k)
		for (int i = 0; i < n - k; ++i)
		{
			for (int j = 0; j < n - k; ++j)
			{
				if (mp[i][j] == -1 || mp[i+1][j] == -1 || mp[i][j] == -1) 
					continue;
				if (mp[i][j] == mp[i + 1][j + 1] &&
					mp[i][j] == mp[i + 1][j] &&
					mp[i][j] == mp[i][j + 1])
				{
					mp[i][j] += 1;
					ans = max(ans, mp[i][j]);
				}
			}
		}
	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < n; ++j)
	//		cout << mp[i][j] << " ";
	//	cout << endl;
	//}
	cout << ans + 1 << endl;
	return 0;
}
```