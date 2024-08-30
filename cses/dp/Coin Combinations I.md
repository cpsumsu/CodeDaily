---
Difficulty: "fundamental"
tags: ["dp"]
---

> Problem: [Coin Combinations I](https://cses.fi/problemset/result/10356402/)

# 思路
- 又又又是一條 [Dice Combinations](./Dice%20Combinations.md) 的變異題 （看代碼就知道 :）。不如說，這條才題所有 dp 的起點，其他題目，包抱 [Dice Combinations](./Coin%20Combinations%20I.md) 和 [Minimizing Coins](./Minimizing%20Coins.md) 都是它的變種題
- 唯一不同的是裏面 for loop 不受外層 for loop 限制，在每一個 w 值中循環檢查並加上 dp[w - A[i]] 的值


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

const int64_t MOD = 1e9 + 7;

void run_case() {
    int N, T;
    cin >> N >> T;
    vector<int> A(N);

    for (auto &x : A)    
        cin >> x;

    vector<int64_t> dp(T + 1);
    dp[0] = 1;

    for (int w = 1; w < T + 1; w++) {
        for (int i = 0; i < N; i++) {
            if (w >= A[i])
                (dp[w] += dp[w - A[i]]) %= MOD;
        }
    }

    cout << dp.back () << '\n';
}

int main() {
    fastio
    
    run_case();
    
    return 0;
}
```