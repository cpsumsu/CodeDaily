---
Difficulty: "普及+/提高"
tags: ["構造", "bfs"]
---

> Problem: [P2739 [USACO4.4] 棋盘游戏Shuttle Puzzle](https://www.luogu.com.cn/problem/P2739)

# 思路
- 一道考驗BFS內部優化的問題，在加入Jump操作時候，需要考慮Jump的方向是否無用，加入太多無用的Jump會導致Stack overflow

# 复杂度
- 时间复杂度:
> $O(2^N)$

- 空间复杂度:
> $O(2^N)$
  
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
unordered_map<string, int> mp;
string ans, target;

// stack overflow
//void dfs(string S, string tmp)
//{
//	if (tmp.size() > n * (n + 2)) return;
//	if (mp[S] ||
//		(ans.size() != 0 && tmp.size() > ans.size()))
//		return;
//	if (S == target && 
//		(ans.size() == 0 || tmp.size() < ans.size()))
//		ans = tmp;
//	mp[S] = 1;
//	auto it = S.find(" ");
//	if (it > 1 && S[it - 1] != S[it - 2])
//	{
//		string str = S;
//		swap(str[it - 2], str[it]);
//		dfs(str, tmp + to_string(it - 2 + 1));
//	}
//	// cout << it << " " << S << " " << tmp << endl;
//	// cout << S << " " << S.length() << endl;
//	// WWW BBB
//	// WW WBBB
//	// OR WWWB BB
//	// 左移 + 右移
//	if (it != 0)
//	{
//		string str = S;
//		swap(str[it - 1], str[it]);
//		dfs(str, tmp + to_string(it - 1 + 1));
//	}
//	if (it != n - 1)
//	{
//		string str = S;
//		swap(str[it + 1], str[it]);
//		dfs(str, tmp + to_string(it + 1 + 1));
//	}
//	// WW WBBB 
//	// WWBW BB
//	// JUMP (甚麼時候可以JUMP?)
//	// +1 和 +2 不同時: 0位 和 +2位 交換
//	// -1 和 -2 不同時: 0位 和 -2位 交換
//	// ,n - 2, n - 1:
//	// it, it + 1, it + 2 
//	if (it < n - 2 && S[it + 1] != S[it + 2])
//	{
//		string str = S;
//		swap(str[it + 2], str[it]);
//		dfs(str, tmp + to_string(it + 2 + 1));
//	}
//	mp[S] = 0;
//}

struct st
{
	string str;
	string tmp;
};

bool leq(string a, string b)
{
	for (int i = 0; i < a.size(); ++i)
		if (a[i] < b[i]) return true;
		else if (a[i] > b[i]) return false;
	return false;
}

void bfs(string str)
{
	queue<st> q;
	st o;
	o.str = str;
	o.tmp = "";
	q.push(o);
	while (!q.empty())
	{
		st cur = q.front();
		q.pop();
		string S = cur.str, tmp = cur.tmp;
		if (tmp.size() > n * (n + 2)) return;
		if (ans != "" && tmp.size() > ans.size()) return;
		if (S == target)
		{
			if (ans == "" || leq(tmp, ans))
				ans = tmp;
			continue;
		}
		mp[S] = 1;

		auto it = S.find(" ");
		// cout << it << " " << S << " " << tmp << endl;
		// W只可以向右JUMP，B只可以左JUMP
		// jump
		if (it > 1 && S[it - 1] != S[it - 2] && S[it - 2] == 'W')
		{
			string str = S;
			swap(str[it - 2], str[it]);
			if (mp[str]) continue;
			int next = it - 2 + 1;  string tt;
			if (next >= 10) tt = tmp + char('A' + next - 10);
			else tt = tmp + to_string(next);
			o.str = str, o.tmp = tt;
			q.push(o);
		}
		// 左
		if (it != 0 && S[it - 1] != 'B')
		{
			string str = S;
			swap(str[it - 1], str[it]);
			if (mp[str]) continue;
			int next = it - 1 + 1;  string tt;
			if (next >= 10) tt = tmp + char('A' + next - 10);
			else tt = tmp + to_string(next);
			o.str = str, o.tmp = tt;
			q.push(o);
		}
		if (it != n - 1 && S[it + 1] != 'W')
		{
			string str = S;
			swap(str[it + 1], str[it]);
			if (mp[str]) continue;
			int next = it + 1 + 1;  string tt;
			if (next >= 10) tt = tmp + char('A' + next - 10);
			else tt = tmp + to_string(next);
			o.str = str, o.tmp = tt;
			q.push(o);
		}
		if (it < n - 2 && S[it + 1] != S[it + 2] && S[it + 2] == 'B')
		{
			string str = S;
			swap(str[it + 2], str[it]);
			if (mp[str]) continue;
			int next = it + 2 + 1;  string tt;
			if (next >= 10) tt = tmp + char('A' + next - 10);
			else tt = tmp + to_string(next);
			o.str = str, o.tmp = tt;
			q.push(o);
		}
		mp[S] = 0;
	}
}

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n;
	string str;
	for (int i = 0; i < n; ++i)
		str += "W", target += "B";
	str += " ", target += " ";
	for (int i = 0; i < n; ++i)
		str += "B", target += "W";
	n = 2 * n + 1;
	bfs(str);
	// cout << ans.size() << endl;
	// 哎
	// 每个数字之间以空格分隔，每行20个数(除了最后一行)。
	// 
	int k = 0;
	for (int i = 0; i < ans.size() - 1; ++i)
	{
		k++;
		int res;
		if (ans[i] >= '0' && ans[i] <= '9')
			res = ans[i] - '0';
		else
			res = ans[i] - 'A' + 10;
		if (k % 20 != 0)
			cout << res << " ";
		else
			cout << res << "\n";
	}
	int res;
	if (ans[ans.size() - 1] >= '0' && ans[ans.size() - 1] <= '9')
		res = ans[ans.size() - 1] - '0';
	else
		res = ans[ans.size() - 1] - 'A' + 10;
	cout << res << "\n";
	return 0;
}
```