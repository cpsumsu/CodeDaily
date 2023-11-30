---
Difficulty: "提高+/省选−"
tags: ["拓撲排序"]
---

> Problem: [P2741 [USACO4.4] 重叠的图像Frame Up](https://www.luogu.com.cn/problem/P2741)

# 思路
- 我們可以把每個英文字母的最左下角以及最右上角的位置記錄下來
- 然後用這兩個位置來構建一個空心長方形，在這個空心長方形上找到別的英文字母，找到也就是這個圖形在這個字母的下面。
- 最後使用拓撲排序來排序，輸出即可

# 复杂度
- 时间复杂度:
> $O(hw)$

- 空间复杂度:
> $O(hw)$
  
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
const int N = 50; // 用於定義常量數組
#define MAXN ((int) 1e5) //
#define MAXM ((int) 1e5)
#define MAXPROD ((int) 1e5)

int h, w;
vector<string> map;
struct Pinfo
{
	int mx, my;
	int nx, ny;
};


Pinfo lis[N];
int RRank[N][N];
int rd[N], vis[N];
unordered_map<int, bool> mp;
int cnt;
char ans[26];

void topoSort(int l) 
{
	if (l == cnt)
	{
		printf("%s\n", ans);
		return;
	}
	for (int u = 0; u < 26; ++u)
	{
		if (!mp[u]) continue;
		if (rd[u] == 0)
		{
			for (int i = 0; i < N; ++i)
				if (RRank[i][u]) rd[i]--;
			ans[l] = u + 'A';
			// cout << u << endl;
			mp[u] = false;
			topoSort(l + 1);
			mp[u] = true;
			for (int i = 0; i < N; ++i)
				if (RRank[i][u]) rd[i]++;
		}
	}
}


int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> h >> w;
	map.resize(h);
	for (int i = 0; i < h; ++i)
		cin >> map[i];
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
		{
			if (map[i][j] == '.') continue;
			int idx = map[i][j] - 'A';
			if (mp[idx])
			{
				Pinfo& o = lis[idx];
				o.mx = max(o.mx,i), o.nx = min(o.nx,i);
				o.my = max(o.my,j), o.ny = min(o.ny,j);
			}
			else
			{
				mp[idx] = true;
				cnt++;
				Pinfo o;
				o.mx = i, o.nx = i;
				o.my = j, o.ny = j;
				lis[idx] = o;
			}
		}
	//for (auto [u, v] : mp)
	//{
	//	cout << char(u + 'A') << " " << lis[u].mx
	//		<< " " << lis[u].my
	//		<< " " << lis[u].nx
	//		<< " " << lis[u].ny << endl;;
	//}
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			for (auto [u, v] : mp)
			{
				// nx -> mx
				// 
				// XXXXX 
				// X   X
				// X   X
				// XXXXX
				int ii, jj;
				for (ii = lis[u].nx; ii <= lis[u].mx; ++ii)
				{
					jj = lis[u].ny;
					if (map[ii][jj] != '.' && map[ii][jj] - 'A' != u) 
						RRank[map[ii][jj] - 'A'][u] = 1;
					jj = lis[u].my;
					if (map[ii][jj] != '.' && map[ii][jj] - 'A' != u) 
						RRank[map[ii][jj] - 'A'][u] = 1;
				}
				for (jj = lis[u].ny + 1; jj <= lis[u].my - 1; ++jj)
				{
					ii = lis[u].nx;
					if (map[ii][jj] != '.' && map[ii][jj] - 'A' != u) 
						RRank[map[ii][jj] - 'A'][u] = 1;
					ii = lis[u].mx;
					if (map[ii][jj] != '.' && map[ii][jj] - 'A' != u) 
						RRank[map[ii][jj] - 'A'][u] = 1;
				}
			}
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (RRank[i][j]) rd[i]++;
	topoSort(0);
	return 0;
}
```