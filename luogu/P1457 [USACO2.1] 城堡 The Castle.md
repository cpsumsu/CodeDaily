---
Difficulty: "提高+/省选−"
tags: ["搜索", "枚舉"]
---

> Problem: [P1457 [USACO2.1] 城堡 The Castle](https://www.luogu.com.cn/problem/P1457)

# 思路
- 總共有四個問題，可拆分為兩部分，第一部分求房子的最大面積和數量，第二部分求拆牆後的最大面積和位置
- 第一部分很經典的搜索，dfs 和 bfs 都可以。很像一道求島和顏色的經典問題 （詳細 略
- 第二部分依靠第一部分求出的面積和顏色 （將每個房間分為不同顏色都區分是否走過和是否不同的房間），把面積的值按顏色存儲 （因為每個房間的顏色都不同）
- 搜索每個格子，只要有牆，那就拆了（不過要注意不能拆到外牆），然後用顏色檢查是否相同的房間 （雖然有牆隔著，但有可能是相通），把兩個房間的面積加在一起

## 神奇的二進制魔法
1 2 4 8 分別為不同的方向，那麼根據二進制的特性，可以用

```cpp
for (int k = 0; k < 4; k++)
	if (grid[i][j] & (1 << k))
		cout << "no walls!!!" << '\n';
	else
		cout << "have walls" << '\n';

```
來判斷是否有牆, 而且也能夠用 k 來找到方向

```cpp
const string direction = "WNES";
cout << direction[k] << '\n';
```


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

void run_case() {
    int N, M;
    cin >> M >> N;

    vector<vector<int>> grid(N, vector<int>(M, 0));
    for (auto &line : grid)
        for (auto &x : line)
            cin >> x;

    queue<pair<int, int>> island;
    vector<vector<int>> visited(N, vector<int>(M, false));
    const vector<pair<int, int>> direction {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    vector<int> cached(50 * 50 + 10);					// 存儲面積
    int color = 1, rooms = 0, max_area = 0;

    for (int i = 0; i < N; i++) {						// 經典 BFS
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                visited[i][j] = color;					// 用顏色區分房子
                rooms++;
                int area = 1;							// 至少有一個格子
                island.push({i, j});

                while (island.size()) {
                    auto t = island.front();
                    island.pop();

                    for (int k = 0; k < 4; k++) {
                        if (!(grid[t.first][t.second] & (1 << k))) {			// 神奇的兩進制魔法 :)
                            int tx = t.first + direction[k].first;
                            int ty = t.second + direction[k].second;

                            if (visited[tx][ty]) continue;			// 不用額外檢查 tx, ty 是否出界，因為不拆牆

                            visited[tx][ty] = color;
                            island.push({tx, ty});
                            area++;
                        }
                    }
                }

                max_area = max(max_area, area);
                cached[color] = area;					// 用顏色存儲面積
                color++;
            }
        }
    }

    cout << rooms << '\n' << max_area << '\n';

    int ti = 0, tj = 0;
    char ch;
    const string icon = "_NE_";						// 只需要考慮北和東

    for (int j = 0; j < M; j++) {
        for (int i = N - 1; i >= 0; i--) {
            for (int k = 1; k < 3; k++) {			// 北和東的 bit
                if (grid[i][j] & (1 << k)) {
                    int tx = i + direction[k].first;
                    int ty = j + direction[k].second;

                    if (tx < 0 || tx >= N || ty < 0 || ty >= M) continue;		// 不能拆外牆哦！
                    
                    int c1 = visited[i][j], c2 = visited[tx][ty];
                    int total = cached[c1] + cached[c2];						// 每個房間的顏色不同，所以用作 key 存儲面積

                    if (c1 != c2 && max_area < total) {
                        max_area = total;
                        ti = i;
                        tj = j;
                        ch = icon[k];
                    }
                }
            }
        }
    }

    cout << max_area << '\n' << ti + 1 << ' ' << tj + 1 << ' ' << ch << '\n';
}

int main() {
    run_case();
    
    return 0;
}
```
