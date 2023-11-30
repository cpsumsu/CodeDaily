---
Difficulty: "提高+/省选−"
tags: ["强連通分量", "Tarjan", "DFS"]
---

> Problem: [P2746 [USACO5.3] 校园网Network of Schools](https://www.luogu.com.cn/problem/P2746)

# 思路
- 子任务 A：为了使软件按照协议到达网络中的所有学校，必须收到新软件副本的最少学校数量。
  - 求收缩强连通分量（SCC，strongly connected components）后形成的新图中入度为 0 的顶点数。
- 子任务 B：必须进行最少数量的扩展，以便无论我们将新软件发送到哪个学校，它都能到达所有其他学校。
  - 求出需要添加的边数才能使整个图强连通。

# Tarjan 算法
Tarjan 算法基于以下事实：
- DFS 搜索生成 DFS 树/森林
- 强连通分量形成 DFS 树的子树。
- 如果我们能找到这样的子树的头，我们就可以打印/存储该子树中的所有节点（包括头），这将是一个 $SCC$ 。
- 从一个 $SCC$ 到另一个$SCC$ 没有后边（可以有交叉边，但在处理图形时不会使用交叉边）。
# 强連通分量
- 有空寫

# 解題方法
解决方案涉及使用 Tarjan 算法来查找强连通分量，并将每个分量视为单个顶点（称为顶点收缩）。
- 在收缩图中，设入度为0的顶点数为 $a$ ，出度为0的顶点数为 $b$。
- 第一个问题的答案是 $a$，第二个问题的答案是 $max(a,b)$。

# 复杂度
- 时间复杂度:
> $O(N^2)$

- 空间复杂度:
> $O(1)$
  
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
#include <stack>
// #include <map>
using namespace std;

typedef long long LL;
typedef long long int lli;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x7f7f7f7f; // 最大值2139062143。用於代替INT_MAX 
const int N = 100 + 10; // 用於定義常量數組
#define MAXN ((int) 1e5) //
#define MAXM ((int) 1e5)
#define MAXPROD ((int) 1e5)

vector<vector<int>> mp;
int dfn[N], low[N], timestamp;
stack<int> stk;
bool in_stk[N];
int id[N], scc_cnt;
int in[N], out[N];

// 對mp加入邊
void add(int a, int b)
{
	mp[a].push_back(b);
}

// tarjan 算法
void tarjan(int u)
{
	dfn[u] = low[u] = ++timestamp;
	stk.push(u); in_stk[u] = true; // 記錄當前邊是否在棧中
	for (auto v : mp[u])
	{
		int j = v;
		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if (in_stk[j])
			low[u] = min(low[u], dfn[j]);
	}
	if (dfn[u] == low[u])
	{
		++scc_cnt;
		int v;
		do {
			v = stk.top(); stk.pop();
			in_stk[v] = false;
			id[v] = scc_cnt;
		} while (v != u);
	}
}

// 强连通分量 Tarjan
int main()
{
	int n;
	cin >> n;
	mp.resize(N);
	for (int i = 1; i <= n; ++i)
	{
		int t;
		while (cin >> t, t)
			add(i, t);
	}
	// tarjan
	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; ++i)
		for (auto e : mp[i])
		{
			int k = e;
			int a = id[i], b = id[k];
			if (a != b) out[a]++, in[b]++;
		}
	int src = 0, des = 0;
	for (int i = 1; i <= scc_cnt; ++i)
	{
		if (!in[i]) src++;
		if (!out[i]) des++;
	}
	cout << src << "\n";
	if (scc_cnt == 1) printf("0");
	else printf("%d\n", max(src, des));
	return 0;
}
```