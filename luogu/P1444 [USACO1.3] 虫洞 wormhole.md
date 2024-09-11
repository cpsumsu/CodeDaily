---
Difficulty: "普及/提高−"
tags: ["dfs"]
---

> Problem: [P1444 [USACO1.3] 虫洞 wormhole](https://www.luogu.com.cn/problem/P1444)

# 思路
- 先看 [Sino_E](https://www.luogu.com.cn/problem/solution/P1444) 題解
- Bessie 只會往 x 正方向走，所以會一直走右邊 （注意，座標 (1, 1), (3, 1) 是卡笛爾座標），因此，用 sort 把相同 y 的分配一起，就知道 i 的洞往右走能不能到下一個洞
- 目標很簡單，用 dfs 把圖走一遍，每遇到一個未匹配的洞，將現在的洞 step 匹配到 i 洞。
- 把所有洞匹配之後，查有沒有循環
- 查循環的 function 也挺有趣的，path[x] 指 x 洞有沒有下個洞，要是有，就看下是否訪問過，`x = match[path[x]]` 得到匹配的洞的座標 index （因為 Bessie 下一步要去匹配的洞)


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

int sol = 0;
int N;
vector<pair<int, int>> A;
vector<int> path, match;

bool have_cycle() {
    for (int i = 0; i < N; i++) {
        vector<bool> visited(N, false);

        for (int x = i; path[x] != -1; x = match[path[x]]) {
            if (visited[x])
                return true;
            visited[x] = true;
        }
    }

    return false;
}

void dfs(int step) {
    if (step == N) {
        if (have_cycle())
            sol++;

        return ;
    }

    if (match[step] != -1) 
        dfs(step + 1);
    else {
        for (int i = step + 1; i < N; i++) {
            if (match[i] == -1) {
                match[i] = step;
                match[step] = i;
                dfs(step + 1);
                match[i] = match[step] = -1;
            }
        }
    }
}

void run_case() {
    cin >> N;

    A.resize(N);
    path.resize(N, -1);
    match.resize(N, -1);

    for (auto &[a, b] : A)    
        cin >> a >> b;

    sort(A.begin(), A.end(), [](auto &x, auto &y) {
        return x.second == y.second ? x.first < y.first : x.second < y.second;
    });

    for (int i = 1; i < N; i++)
        if (A[i - 1].second == A[i].second)
            path[i - 1] = i;

    dfs(0);
    cout << sol << '\n';
}

int main() {
    fastio
    
    run_case();
    
    return 0;
}
```
