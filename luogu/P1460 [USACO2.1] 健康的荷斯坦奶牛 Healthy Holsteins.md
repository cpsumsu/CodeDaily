---
Difficulty: "普及−"
tags: ["DFS"]
---

> Problem: [P1460 [USACO2.1] 健康的荷斯坦奶牛 Healthy Holsteins](https://www.luogu.com.cn/problem/P1460)

# 思路
> DFS

# 解题方法
> 每一次的DFS都是選和不選的過程，選了則cnt+1，不選則cnt不變，最後取最小值即可

# 复杂度
- 时间复杂度:
> $O(mn)$

- 空间复杂度:
> $O(50 * 50)$
  


# Code
```C++ []
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

int moves[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }; // 4向移動 順時針
// int moves[8][2] = { {0,1},{1,0},{-1,0},{0,-1}, {1,1},{-1,1},{1,-1},{-1,-1} }; // 8向移動
// int moves[6][2] = { {0,1},{1,0},{1,-1},{0,-1},{-1,0},{-1,1} }; // 六邊移動 (網格六邊形專用)

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

// 檢查是否是質數
bool isprime(int x)
{
	if (x < 2) return false;
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0) return false;
	return true;
}

// 檢查是否是回文數、回文串
bool ok(int i)
{
	string s = to_string(i);
	int n = s.size();
	for (int i = 0; i < n; ++i)
		if (s[i] != s[n - 1 - i]) return false;
	return true;
}

int n, m;
vector<int> cow, ans, aaa;
vector<vector<int>> feeds;
bool isok(int cur)
{
	for (int i = 0; i < n; ++i)
	{
		int s = 0;
		for (int j = 0; j < cur; ++j)
			s += feeds[aaa[j]][i];
		if (s < cow[i]) 
			return false;
	}
	return true;
}

int mn = INF;
void dfs(int cur, int cnt)
{
	// cout << cur << " " << cnt << endl;
	if (cur == m)
	{
		if (isok(cnt))
		{
			if (cnt < mn)
			{
				mn = cnt;
				for (int i = 0; i < cnt; ++i)
					ans[i] = aaa[i] + 1;
			}
		}
		return;
	}
	aaa[cnt] = cur;
	dfs(cur + 1, cnt + 1);
	dfs(cur + 1, cnt);
}

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n;
	cow.resize(50);
	aaa.resize(50);
	for (int i = 0; i < n; ++i)
	{
		cin >> cow[i];
	}
	cin >> m;
	feeds.resize(50, vector<int>(50));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> feeds[i][j];
	ans.resize(50);
	dfs(0, 0);
	cout << mn << " ";
	for (int i = 0; i < mn; ++i)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
```