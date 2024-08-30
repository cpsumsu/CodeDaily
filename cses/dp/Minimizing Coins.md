---
Difficulty: "fundamental"
tags: ["dp"]
---

> Problem: [Minimizing Coins](https://cses.fi/problemset/task/1634)

# 思路
- 與上一題 [Dice Combination](./Dice%20Combinations.md) 有點不同，這題不是找所有的 combination，且找出最少的長度（元素的總量）
- 因此，先初始化元素為 INF， dp[0] = 0 （因為加上零不會影響最少的長度，不然答案可以是 0 + 0 + 0 + ... + 1 + 5 + 5 = 11）
- 求最少用 min()，每次加一個元素，dp[i] 加上 1


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

const int INF = 1e9 + 7;

void run_case() {
    int N, T;
    cin >> N >> T;
    vector<int> A(N);

    for (auto &x : A)    
        cin >> x;

    vector<int> dp(T + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int w = A[i]; w < T + 1; w++) {
            dp[w] = min(dp[w], dp[w - A[i]] + 1);
        }
    }

    cout << (dp.back() == INF ? -1 : dp.back()) << '\n';
}

int main() {
    fastio
    
    run_case();
    
    return 0;
}
```
