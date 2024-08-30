---
Difficulty: "fundamental"
tags: ["dp"]
---

> Problem: [Coin Combinations II](https://cses.fi/problemset/task/1636/)

# 思路
- 怎麼說好呢？這題和前一題沒啥區別，唯一不同在於這題不同硬幣的順序會影響到結果
- 在代碼裏面，兩層 for loop 順序不同了，因為順序問題，需要順序地遍歷每一個元素。

舉個例子：
前一題可以 -> 2 + 3 + 2 + 3
這題只能  -> 2 + 2 + 3 + 3

在 dp 數組中，這題需要先遍歷所有的 2 ，才能遍歷 3或後面的元素. 而上題在每個數值 w 中，遍歷所有元素，即意味著在 w - 2 中選了元素 3， 那麼在 w 中可以選 2， 答案就不按順序了。

而這題就需要先選了 2（可以選很多個 2），全選完才能開始選 3 

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

    for (int i = 0; i < N; i++) {
        for (int w = 1; w < T + 1; w++) {
            if (w >= A[i])
                (dp[w] += dp[w - A[i]]) %= MOD;
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