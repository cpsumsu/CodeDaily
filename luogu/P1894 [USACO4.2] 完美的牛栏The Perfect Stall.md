---
Difficulty: "普及+/提高"
tags: ["二分圖", "匈牙利算法"]
---

> Problem: [P1894 [USACO4.2] 完美的牛栏The Perfect Stall](https://www.luogu.com.cn/problem/P1894)

# 思路
- 二分圖 + 匈牙利算法，
- 二分圖: 所有的點分成兩個集合，所有的邊的端點都在不同的集合，也可以說沒有奇數邊的環，這題就可以把牛看做一個集合，把牛欄看做另一個集合，一頭牛 喜歡某個牛欄說明這兩點之間有邊。
- find函數為匈牙利算法

# Code
```C++ 
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string.h>
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
const int N = 225; // 用於定義常量數組

int cow[N][N]; 
int vis[N], houses[N]; // houses: 牛棚去牛那裡
int n, m;

// 匈牙利算法
bool find(int x)
{
	for (int i = 1; i <= m; ++i)
	{
		if (!vis[i] && cow[x][i] == 1) // 未訪問且有邊
		{
			vis[i] = 1; // 訪問
			if (houses[i] == 0 || find(houses[i])) // 找牛棚
			{
				houses[i] = x; // 牛棚給牛
				return true; // 
			}
		}
	}
	return false;
}

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j)
		{
			int tmp;
			cin >> tmp;
			cow[i][tmp] = 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		memset(vis, 0, sizeof(vis)); // 所有牛棚都未訪問
		if (find(i)) ans++; // 可以住牛棚的話++
		// cout << i << endl;
	}
	cout << ans << endl;
	return 0;
}
```