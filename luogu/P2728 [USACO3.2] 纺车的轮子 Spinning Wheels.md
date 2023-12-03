---
Difficulty: "普及/提高−"
tags: ["模擬"]
---

> Problem: [P2728 [USACO3.2] 纺车的轮子 Spinning Wheels](https://www.luogu.com.cn/problem/P2728)

# 思路
> 模擬。循環找 `(j + st) % 360`

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
#include <map>
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
vector<int> speed;
vector<vector<bool>> wheel;
// 
vector<int> moved;

bool check()
{
	int res;
	for (int i = 0; i < 360; ++i)
	{
		res = 0;
		for (int j = 0; j < 5; ++j)
			if (wheel[j][(moved[j] + i) % 360]) res++;
		if (res == 5) return true;
		//cout << res << endl;
	}
	return false;
}
void sadd()
{
	for (int i = 0; i < 5; ++i)
	{
		moved[i] = (moved[i] - speed[i] + 360) % 360;
	} 
	//cout << "..." << endl;
	//for (int i = 0; i < 5; ++i)
	//{
	//	for (int k = 0; k < wheel[i].size(); k++)
	//	{
	//		cout << wheel[i][k] << " ";
	//	}
	//	cout << endl;
	//}
}

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	speed.resize(5, 0);
	wheel.resize(5,vector<bool>(1145,false));
	moved.resize(5, 0);
	for (int i = 0; i < 5; ++i)
	{
		cin >> speed[i];
		int w;
		cin >> w;
		for (int k = 0; k < w; ++k)
		{
			int st, ed;
			cin >> st >> ed;
			for (int j = 0; j <= ed; ++j)
			{
				// cout << (j + st) % 360 << endl;
				wheel[i][(j + st) % 360] = true;
			}
		}
	}
	for (int t = 0; t < 360; ++t)
	{
		if (check())
		{
			cout << t << endl;
			return 0;
		};
		//cout << "ok" << endl;
		sadd();
	}
	cout << "none" << endl;
	return 0;
}
```