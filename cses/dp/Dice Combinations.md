---
Difficulty: "Hard"
tags: ["dp"]
---

> Problem: [Dice Combinations](https://cses.fi/problemset/task/1633/)

# 思路
- bottom-up dynamic programming approach
- i 代表得到的值，j 代表 1 - 6
- 每一格 dp[i] 代表在目前 i 值中，可以得到的最大值。兩個 for loop 表示：在 i 值中，看下 i - j 中加上 1 - 6 來試試那個值能不能得到 i 值 -> `dp[i - j]`, 如果有符合的 i - j 值, 就加上它的總量
- dp.back() 代表在 T 值中能得到的最大的值（number of ways)


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

const int MOD = 1e9 + 7;

void run_case() {
    int T;
    cin >> T;

    vector<int64_t> dp(T + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= i && j <= 6; j++) {
            (dp[i] += dp[i - j]) %= MOD;
        }
    }    

    cout << dp.back() << '\n';
}

int main() {
    fastio
    
    run_case();
    
    return 0;
}
```
