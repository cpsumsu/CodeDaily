---
Difficulty: "普及/提高−"
tags: ["搜索"]
---

> Problem: [P1215 [USACO1.4] 母亲的牛奶 Mother's Milk](https://www.luogu.com.cn/problem/P1215)

# 思路
> 先看一下首個[題解](https://www.luogu.com.cn/problem/solution/P1215)，講得十分清楚 

- 又是一條枚舉題。。。只不過需要用到 cach 來儲存已搜索過旳結果，因為是三個變量，那就用三維數組 visited[22][22][22]，其中 1 <= a <= b <= c <= 20
- 中間的兩個循環模擬倒奶，其中 0 代表 a, ..., 2 代表 c, 要是 i == j 就代表把牛奶倒進同一杯中，可跳過 (i, j 代表從牛奶從 i 杯倒進 j 杯)
- `milk[j] != cur[j] && cur[i] > 0` 檢查 j 杯是否滿了，再檢查 i 杯是否為空 (milk 代表杯的容量, cur 代表現有的牛奶容量)
- 每次倒完 (dfs) 後都要還完到未倒的狀態，所以加減 `moved`
  

# Code
```cpp
#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <cstring>
#include <stack>
#include <list>
#include <deque>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <cstdint>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

const int MAX = 22;
vector<int> milk(3);
vector<bool> sol(MAX);
bool visited[MAX][MAX][MAX];

void dfs(vector<int> &cur) {
	if (visited[cur[0]][cur[1]][cur[2]])
		return ;

	visited[cur[0]][cur[1]][cur[2]] = true;
	if (cur[0] == 0)							// 當滿足要求，a 杯為空，記綠下 c 杯的容量
		sol[cur[2]] = true;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j)
				continue;

			if (milk[j] != cur[j] && cur[i] > 0) {
				int moved = min(cur[i], milk[j] - cur[j]);		// 要是 i 杯比 j 杯剩下的容量少，那將 i 杯倒空為止
				cur[j] += moved;
				cur[i] -= moved;

				dfs(cur);

				cur[j] -= moved;
				cur[i] += moved;
			}
		}
	}
}

void run_case() {
	cin >> milk[0] >> milk[1] >> milk[2];
	vector<int> init {0, 0, milk[2]};		// 最初只有 c 杯是滿的

	dfs(init);

	for (int i = 0; i < MAX; i++)
		if (sol[i])
			cout << i << ' ';
}

int main() {
    fastio
    
    run_case();
    
    return 0;
}
```
