---
Difficulty: "提高+/省选−"
tags: ["二维凸包"]
---

> Problem: [P2742 [USACO5.1] 圈奶牛Fencing the Cows /【模板】二维凸包](https://www.luogu.com.cn/problem/P2742)

# 思路
- 二维凸包就是要在多個點中找出一組點，這一組點把圖內的所有點給包起來。(跟題目要求的一模一樣)
- 思路來源: https://www.luogu.com.cn/problem/solution/P2742

# 難點
- 距離函數和方向函數要記得怎麼寫

# 复杂度
- 时间复杂度:
> $O(nh)$

- 空间复杂度:
> $O(nh)$
  
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
#include <stack>
#include <cmath>
// #include <map>
using namespace std;
typedef pair<double, double> PDD;

int n;
int main()
{
	cin >> n;
	double ans = 0;
	vector<PDD> m(114514, {0,0});
	vector<PDD> st(114514 , {0,0});
	for (int i = 1; i <= n; ++i)
	{
		cin >> m[i].first >> m[i].second;
		if (i != 1 && m[i].second < m[1].second)
		{
			swap(m[i].second, m[1].second);
			swap(m[i].first, m[1].first);
		}
	}
	auto distance = [&](const PDD& A, const PDD& B) -> double
		{
			return sqrt(
				(B.first - A.first) * (B.first - A.first) +
				(B.second - A.second) * (B.second - A.second));
		};
	auto dir = [&](const PDD& A, const PDD& B, const PDD& C, const PDD&D) -> double
		{
			return 
				(B.first - A.first) * (D.second - C.second) -
				(B.second - A.second) * (D.first - C.first);
		};
	auto cmp = [&](auto a, auto b)
		{
			double num = dir(m[1], a, m[1], b);
			if (num > 0)
				return 1;
			if (num == 0 &&
				distance(m[0], a) < distance(m[0], b))
				return 1;
			return 0;
		};
	sort(m.begin() + 2, m.begin() + 1 + n, cmp);
	// 入棧 (用數組模擬棧，因為可能要一直後退)
	st[1] = m[1];
	int h = 1; // st.size()
	for (int i = 2; i <= n; ++i)
	{ 
		// 後退
		// Graham算法裡 while(top&&Side(st[top-1],st[top],p[i])<=0) 這句話裡的 <= 應該寫成 <
		while (h > 1 && dir(st[h - 1], st[h], st[h], m[i]) < 0)
			h--; // pop
		h++;
		st[h] = m[i]; // push
	}
	st[h+1] = m[1]; // 最後一點相連
	for (int i = 1; i <= h; ++i)
	{
		ans += distance(st[i], st[i + 1]);
	}
	printf("%.2lf\n", ans);
	return 0;
}
```