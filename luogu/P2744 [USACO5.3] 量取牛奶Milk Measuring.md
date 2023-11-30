---
Difficulty: "提高+/省选−"
tags: ["DP", "DFS"]
---

> Problem: [P2744 [USACO5.3] 量取牛奶Milk Measuring](https://www.luogu.com.cn/problem/P2744)

# 思路
- DFS + DP

# DP
- 先建立起 idx 和 vis 數組
- idx 記錄每一量q所需的最小桶數。
- $i$ 是每個桶的編號， $j$ 是每一可能的牛奶量
- 如果 $j>=A[i]$ ，代表當前桶可以容納 $j$ 量
- 如果用當前桶容納 $j$ ，且 $\text{先前用桶數}+1<=\text{目前記錄的}idx[j]$ ，則更新 $idx[j]$ ，並標記 $vis[j]=1$ 表示用過當前桶
- $cur = vis[j - A[i]] ^ 1$ ，記錄是否使用過 $j-A[i]$ 的桶

# DFS
- DFS 中從 $a + 1$ 開始選，選到p為止

# 复杂度
- 时间复杂度:
> $O(PQ)$

- 空间复杂度:
> $O(P)$
  
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
	int q, p;
	cin >> q >> p;
	vector<int> A(211451), idx(211451), vis(114514);
	vector<int> dp(114514, 0), ans(114);
	for (int i = 1; i <= p; ++i) cin >> A[i];
	sort(A.begin() + 1, A.begin() + p + 1);
	idx[0] = 0;
	// 记录每一量q需要的最小桶数。
	for (int i = 1; i <= q; ++i) idx[i] = INF;
	// i是每個桶的編號,j是每一可能的牛奶量
	for (int i = 1; i <= p; ++i)
		for (int j = 0; j <= q; ++j)
		{
			vis[j] = 0;
			// 如果j>=A[i],意味当前桶可以容纳j量
			if (j >= A[i])
			{
				// cur = vis[j - A[i]] ^ 1,记录是否使用过j-A[i]的桶
				int cur = vis[j - A[i]] ^ 1;
				// 如果用当前桶容纳j,且此前用桶数+1<=目前记录的idx[j]
				if (idx[j - A[i]] + cur <= idx[j])
				{
					// 则更新idx[j],并标记vis[j]=1表示用过当前桶
					idx[j] = idx[j - A[i]] + cur;
					vis[j] = 1;
				}
			}
		}
	//  如果有桶大小為1, 2
	//	當前量j = 3

	//	可以用大小1的桶子容納2量, 記錄idx[2] = 1
	//	再用大小1的桶子容納剩下的1量, idx[3] = 2
	auto dpp = [&]()->void
		{
			// init dp vector
			dp[0] = 1;
			for (int i = 1; i <= q; ++i) dp[i] = 0;
			for (int i = 1; i <= idx[q]; ++i)
				for (int j = A[ans[i]]; j <= q; ++j)
					if (dp[j - A[ans[i]]]) dp[j] = 1;
			if (dp[q])
			{
				cout << idx[q] << " ";
				for (int i = 1; i <= idx[q]; ++i)
					cout << A[ans[i]] << " ";
				exit(0);
			}
		};
	function<void(int,int)> dfs = [&](const int& a, const int& depth) -> void
		{
			if (depth == idx[q])
			{
				dpp();
				return;
			}
			if (idx[q] - depth > p - a) return;
			// 從 a + 1開始選，選到p為止
			for (int i = a + 1; i <= p; ++i)
			{
				ans[depth + 1] = i;
				dfs(i, depth + 1);
			}
		};
	dfs(0, 0);
	return 0;
}
```