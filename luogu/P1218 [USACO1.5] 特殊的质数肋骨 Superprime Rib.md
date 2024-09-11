---
Difficulty: "普及−"
tags: ["素数判断,质数,筛法"]
---

> Problem: [P1218 [USACO1.5] 特殊的质数肋骨 Superprime Rib](https://www.luogu.com.cn/problem/P1218)

# 思路
> 跟[回文質數](https://www.luogu.com.cn/problem/P1217) 差不多，要是熟識上一題，這題很簡單 ：）
- 首先，先確定真正需要搜索的範圍，因為每一位數字都是質數，所以範圍從 `[10^(n-1), 10^n] -> [10^(n-1)*2 + 1, 10^(n-1)*8]` （因為頭位數字是質數 (2, 3, 5, 7, 9))
- 其次，把這部分的數字也移除 `[10^(n-1)*4, 10^(n-1)*5] and [10^(n-1)*6, 10^(n-1)*7]`
- 在 `check` 裏，每個回圈都檢查下是否質數即可

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

vector<bool> generate_prime(int64_t maximum) {
    vector<bool> sieve(maximum + 1, true);

    sieve[0] = sieve[1] = false;

    for (int64_t i = 2; i <= maximum; i++) {
        if (sieve[i]) {
            for (int64_t j = i * i; j <= maximum; j += i) 
                if (sieve[j])
                    sieve[j] = false;
        }
    }

    return sieve;
}

bool in_range(int64_t x, int64_t unit) {
    if ((unit * 4 <= x && x <= unit * 5) || (unit * 6 <= x && x <= unit * 7))
        return false;
    return true;
}

bool check(int64_t x, int64_t unit, const vector<bool> &primes) {
    if (!in_range(x, unit))
        return false;

    while (x) {
        if (!primes[x])
            return false;

        x /= 10;
    }

    return true;
}

void run_case() {
    int64_t N;
    cin >> N;

    int64_t unit = pow(10, N - 1);
    int64_t l = unit * 2 + 1, r = unit * 8;

    auto primes = generate_prime(r);

    for (int64_t x = l; x <= r; x += 2) {
        if (check(x, unit, primes))
            cout << x << '\n';
    }    
}

int main() {
    fastio
    
    run_case();
    
    return 0;
}
```
