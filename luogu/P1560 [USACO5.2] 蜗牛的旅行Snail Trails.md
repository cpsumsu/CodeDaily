---
Difficulty: "提高+/省选−"
tags: ["DFS"]
---

> Problem: [P2744 [USACO5.3] 量取牛奶Milk Measuring](https://www.luogu.com.cn/problem/P2744)

# 思路
- DFS

# DFS函數注意事項
- 邊界: $i <= 0 || j <= 0 || i > n || j > n || mp[i][j] == 2$
- 方向性: dfs的移動是根據上一步的移動方向來決定的，所以要記錄上一步的移動方向
- 障礙物: 障礙物使用 $2$ 數字表示，自己走的路用 $1$ 數字表示

# 复杂度
- 时间复杂度:
> $O(4^b)$ 每多一個障礙物就會產生至多四個選擇 (好像不太對)

- 空间复杂度:
> $O(1)$
  
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
#include <functional>
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

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int moves[4][2] = { {0,1},{0,-1},{-1,0},{1,0} }; // 4向移動 順時針
	int n, b, ans = INT_MIN;
	cin >> n >> b;
	vector<vector<int>> mp(214, vector<int>(214, 0));
	for (int i = 0; i < b; ++i)
	{
		char ch; int y;
		cin >> ch >> y;
		mp[ch - 'A' + 1][y] = 2; // #
	}
	function<void(int, int, int, int)> dfs = [&](const int& x, const int& y, int dir, const int& steps) -> void
		{
			if (mp[x][y] == 1)
			{
				ans = max(ans, steps);
				return;
			}
			int i = x + moves[dir][0], j = y + moves[dir][1];
			// cout << i << " " << j << endl;
			if (i <= 0 || j <= 0 || i > n || j > n || mp[i][j] == 2)
				for (int v = 0; v < 4; ++v)
				{
					int ii = x + moves[v][0], jj = y + moves[v][1];
					if (ii > 0 && ii <= n && jj > 0 && jj <= n && mp[ii][jj] != 2) // #
					{
						mp[x][y] = 1;
						dfs(ii, jj, v, steps + 1);
						mp[x][y] = 0;
					}
				}
			else
			{
				mp[x][y] = 1;
				dfs(i, j, dir, steps + 1);
				mp[x][y] = 0;
			}
		};
	for (int i = 0; i < 4; ++i) dfs(1, 1, i, 0);
	// test
	cout << ans << endl;
	return 0;
}
```